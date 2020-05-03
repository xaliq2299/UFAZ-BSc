import pandas as pd
import networkx as nx

def degree_connectivity(G,node):
  deg=0
  for n in G.nodes():
    if G.has_edge(n,node):
      deg += 1
    if G.has_edge(node,n):
      deg += 1
  return deg

def closeness_centrality(G,node,w):
  dist=0
  for n in G.nodes():
    path=nx.shortest_path(G, source=node, target=n, weight=w)
    for i in range(len(path)-1):
      dist += G.edges[path[i], path[i+1]][w]
  return (len(list(G.nodes))-1)/dist

def betweenness_centrality(G,node,w):
  n=0
  for i in G.nodes():
    if i == node:
      continue
    for j in G.nodes():
      if j == node:
        continue
      path=nx.shortest_path(G, source=i, target=j, weight=w)
      if node in path:
        n += 1
  return n

def network_density(G):
  N=len(G.nodes())
  sum=0
  for node in G.nodes():
    sum += degree_connectivity(G,node)
  return sum/N/(N-1)

def network_diameter(G):
  longest=0
  path=[]
  nNodes=0
  for i in G.nodes():
    for j in G.nodes():
      if i != j:
        path=nx.shortest_path(G, source=i, target=j)
      dist=0
      for k in range(len(path)-1):
        dist += G.edges[path[k], path[k+1]]['Hours']
      if dist>longest:
        #print(dist)
        longest=dist
        nNodes=len(path)-1
  return nNodes 


'''Cities in AZE'''
#uploaded = files.upload() # was important to load files while working with Colab
#data_cities = io.BytesIO(uploaded['cities_in_az.csv']) # to read files
data_cities = pd.read_csv('cities_in_az.csv')
print(data_cities)
#print(data_cities.head())
#print(data_cities.columns)
G=nx.from_pandas_edgelist(data_cities, source='Origin', target='Destiny', edge_attr=True, create_using=nx.DiGraph) # NEW
#print(nx.shortest_path(G, source='Alat', target='Shamakhi', weight=None))

# visualizing the graph
plt.figure()
nx.draw_networkx(G, with_labels=True)
plt.show()

#print(G.degree('Shirvan'))
#print(G.in_degree('Alat'))
#print(G.out_degree('Baku'))

# Column 'Hours' is a weight of interest
path=nx.shortest_path(G, source='Baku', target='Imishli', weight=None)
print(path)
path=nx.shortest_path(G, source='Baku', target='Imishli', weight='Hours')
print(path)
# There is a difference between the paths above since weight is taken into account
# 1st case (without weight): 1.77+1.83=3.6
# 2nd case (with weight='Hours'): 1.13+0.83+1.38=3.34

nx.add_path(G, ['Baku','Imishli'])
G.edges['Baku','Imishli']['Hours']=1.29
print(data_cities)

path=nx.shortest_path(G, source='Baku', target='Imishli', weight='Hours')
print(path)
path=nx.shortest_path(G, source='Imishli', target='Baku', weight='Hours')
print(path)

# visualizing the graph
plt.figure()
nx.draw_networkx(G, with_labels=True)
plt.show()

'''Airports'''
data_airports = pd.read_csv('airports.csv')
#print(data_airports)
#print(data_airports.head())
#print(data_airports.columns)
A=nx.from_pandas_edgelist(data_airports, source='Origin', target='Dest', edge_attr=True) # A stands for Airports

# visualizing the graph
plt.figure()
nx.draw_networkx(A, with_labels=True)
plt.show()

path=nx.shortest_path(A, source='CRP', target='BOI', weight='Distance') # according to Distance
print(path)
path=nx.shortest_path(A, source='CRP', target='BOI', weight='AirTime') # according to AirTime
print(path)


print(degree_connectivity(G,'Kurdamir'))
print(closeness_centrality(G,'Alat','Hours'))
print(betweenness_centrality(G,'Alat','Hours'))
print(network_density(G))
print(network_diameter(G))
