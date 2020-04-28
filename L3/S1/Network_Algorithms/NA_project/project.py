import pandas as pd
import networkx as nx
import numpy as np
import matplotlib.pyplot as plt
import optparse
from scipy import stats

def weather_check(graph, route):
	'''
	checking if weather allow to flight over this route.
	if in any of part it's not allowed to flight, cancel this route
	'''
	for i in range(len(route)-1):
		if int(graph.edges[route[i], route[i+1]]['Weather']) == 0:
			return False
	return True


def add_time(time):
	'''
	calculating adding some value to time
	as there are queues in airports we assume that average time to wait is 15 minutes, in each case arrival and departure
	for this case we consider time between arrival of one flight and departure of another should be more than 30 minutes
	'''
	time_h = int(time/100)
	time_m = int(time%100) + 30
	if time_m >= 60:
		time_m %= 60
		time_h += 1
	return (time_h*100 + time_m)


def time_check(graph, route):
	'''
	when we have different flights we check whether we reach for next flight or not
	'''
	date = ['Year', 'Month', 'DayofMonth']
	for i in range(len(route)-2):
		for j in date:
			if graph.edges[route[i+1], route[i+2]][j] < graph.edges[route[i], route[i+1]][j]:
				return False
		if graph.edges[route[i+1], route[i+2]]['DepTime'] < add_time(graph.edges[route[i], route[i+1]]['ArrTime']):
			return False
	return True
		

def route_sum(graph, route, attr):
	'''
	find sum of given attribute over given route
	'''
	res = 0.
	for i in range(len(route)-1):
		res += float(graph.edges[route[i], route[i+1]][attr])
	return res


def possible_routes(graph, data, origin, dest, price, airtime):
	'''
	nx.all_simple_paths() function generates all pathes between source and target nodes
	cutoff argument precise number of nodes in path
	after check for weather condition and convenient of flights
	we check the cost of travel to be less or equal than price
	and airtime be less or equal than desired time
	'''
	routes = []
	for path in nx.all_simple_paths(graph, source=origin, target=dest, cutoff=5):
		# if weather_check(graph, path) and time_driver(data, path, 0, None):
		if weather_check(graph, path) and time_check(graph, path):
			if price != None and route_sum(graph, path, 'Price') > price:
				continue
			if airtime != None and route_sum(graph, path, 'AirTime') > airtime:
				continue
			routes.append(path)
	return routes


def find_airtime_distance_sum(graph, routes):
	'''
	for given routes find the airtime and distance of route
	'''
	values = [[], []]
	for i in routes:
		values[0].append(route_sum(graph, i, 'AirTime'))
		values[1].append(route_sum(graph, i, 'Distance'))
	return np.array(values)


def print_routes(routes, origin, dest):
	'''
	printing all possible routes in a clear and proper way
	'''
	print("Possible routes from "+str(origin)+" to "+str(dest)+":")
	if len(routes) == 0:
		print("No possible routes.")
		exit()
	if len(routes) <= 10:
		print(routes)
	else:
		print(str(routes[0]) + "\n" + str(routes[1]) + "\n...\n" + str(routes[len(routes)-1]))
	print(str(len(routes))+" routes in total")


def do_analysis(graph,values):
	'''
	creating a scatter plot for analyzing dependency between airtime and distance
	linear fitting of a scatter plot
	deriving average velocity for a plane
	'''
	scatter=plt.scatter(values[0], values[1])
	scatter.set_color("red")
	slope, intercept, r_value, p_value, std_err = stats.linregress(values[0], values[1])
	print("Average velocity = " + str(slope) + " kilometers/mins" + " = " + str(slope*60) + " kilometers/hours")
	plt.plot(values[0], intercept+slope*values[0])
	plt.xlabel('Airtime')
	plt.ylabel('Distance')
	plt.title('Distance over Airtime dependency')
	plt.show()

	plt.figure()
	nx.draw_networkx(graph, with_labels=True)
	plt.show()

	print("==================================================")
	degree_dict = nx.degree_centrality(graph)
	closeness_dict = nx.closeness_centrality(graph)
	betweenness_dict = nx.betweenness_centrality(graph)
	print("The node with maximum degree connectivity: "+str(max(degree_dict, key=degree_dict.get)))
	print("The node with minimum degree connectivity: "+str(min(degree_dict, key=degree_dict.get)))

	print("The node with maximum closeness centrality: "+str(max(closeness_dict, key=closeness_dict.get)))
	print("The node with minimum closeness centrality: "+str(min(closeness_dict, key=closeness_dict.get)))

	print("The node with maximum betweenness centrality: "+str(max(betweenness_dict, key=betweenness_dict.get)))
	print("The node with minimum betweenness centrality: "+str(min(betweenness_dict, key=betweenness_dict.get)))
	#print("Degree connectivity for each node: " +str(degree_dict))
	#print("Closeness centrality for each node: " +str(closeness_dict))
	#print("Betweenness centrality for each node: " +str(betweenness_dict))
	print("Network Diameter: " +str(nx.diameter(graph)))
	print("Network Density: " +str(nx.density(graph)))
	print("==================================================")	



def main():
	#################################################################################
	'''
	get all mentioned options and assign them to variables
	'''
	parser = optparse.OptionParser("usage%prog "+"-o <origin> -d <destination> -p <price> -a <airtime>")
	parser.add_option('-o', dest='origin', type='string', help='origin node of travel')
	parser.add_option('-d', dest='destination', type='string', help='destination node of travel')
	parser.add_option('-p', dest='price', type='float', help='max price of travel')
	parser.add_option('-a', dest='airtime', type='float', help='max airtime of travel')

	(options, args) = parser.parse_args()
	o_node = options.origin
	d_node = options.destination
	max_price = options.price
	max_airtime = options.airtime

	#################################################################################
	'''
	reading data from file and creating graph based on data with links 'Origin' and 'Dest'
	then checking for presence of origin and destination node in graph, if not exit
	checking for origin and destination node to be mentioned during execution
	'''
	pd.options.mode.chained_assignment = None
	flights = pd.read_csv('data.csv')
	G = nx.from_pandas_edgelist(flights, source='Origin', target='Dest', edge_attr=True, create_using=nx.DiGraph)


	if o_node == None or d_node == None:
		print('Error!!! Not mentioning origin or destination node!!!')
		exit()
	if o_node not in G.nodes() or d_node not in G.nodes():
		print('Error!!! Either origin or destination not in graph nodes!!!')
		exit()

	#################################################################################
	'''
	finding and printing all possible routes based on criterias
	getting a list with a sum of airtime and distance of possible routes
	'''
	routes = possible_routes(G, flights, o_node, d_node, max_price, max_airtime)
	print_routes(routes, o_node, d_node)
	values = find_airtime_distance_sum(G, routes)

	#################################################################################
	# Analysis
	do_analysis(G,values)


main()