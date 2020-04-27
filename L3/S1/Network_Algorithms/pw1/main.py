import pandas as pd
import networkx as nx
import io
import matplotlib.pyplot as plt
from google.colab import files


def attribute_for_nodes(G, attribute, default_value):
  for g in G.nodes.keys():
    G.nodes[g][attribute]=default_value

# Depth First Search (DFS) algorithm
def find_path(G,origin,destiny):
  path=[] # list of cities
  keys=G.nodes()
  values=[False]*len(keys)
  visited = dict(zip(keys, values)) # dictionary
  #print(visited)
  
  current=origin
  path.append(current)
  visited[origin]=True # labeling the first node as visited
  while current != destiny:
    neighbors=list(G.neighbors(current)) # getting all adjacent nodes of current node
    for n in neighbors:
      if not visited[n]: # not in path checks whether node was visited or not
        visited[n]=True # labeling the current node as visited
        current=n
        path.append(current) # pushing to stack = appending to list
        break
      else:
        allVisited = True
        for i in list(G.neighbors(current)):
          if visited[i] == False:
            allVisited = False
        if allVisited: # dead end check
          path.pop()
          current=path[len(path)-1]
          break
        else: # if current node still has unvisited nodes
          continue
  return path
    
def calc_hours(G,origin,destiny):
  hours=0.0
  path=find_path(G,origin,destiny)
  #print(path)
  for i in range(len(path)-1):
    hours += float(G.edges[path[i],path[i+1]]["Hours"])
  return hours

def calc_distance(G,origin,destiny):
  dist=0.0
  path=find_path(G,origin,destiny)
  #print(path)
  for i in range(len(path)-1):
    dist += float(G.edges[path[i],path[i+1]]["Distance"])
  return dist

def calc_time(G,origin,destiny):
  time=0.0
  path=find_path(G,origin,destiny)
  #print(path)
  for i in range(len(path)-1):
    time += float(G.edges[path[i],path[i+1]]["AirTime"])
  return time


#uploaded = files.upload() # was important to load files while working with Colab
#data_cities = io.BytesIO(uploaded['cities_in_az.csv']) # to read file
#data_airports = io.BytesIO(uploaded['airports.csv']) # to read file
data_cities = pd.read_csv('cities_in_az.csv')
data_airports = pd.read_csv('airports.csv')

#print(data_cities)
#print(data_airports)
#print(data_cities.head())
#print(data_airports.head())
#print(data_cities.columns)
#print(data_airports.columns)
G=nx.from_pandas_edgelist(data_cities, source='Origin', target='Destiny', edge_attr=True)
A=nx.from_pandas_edgelist(data_airports, source='Origin', target='Dest', edge_attr=True) # A stands for Airports

# functionalities that networkx offers regarding the nodes and edges of graph (G or A in our program)
#print(G.nodes())
#print(G.nodes['Baku'])
#print(G.nodes['Baku']['Hours']) # didn't work
#print(G.edges())
#print(G.edges['Baku',"Alat"])
#print(G.edges['Baku',"Alat"]["Hours"])
#print(list(G.neighbors("Shirvan")))

# visualizing the graphs
plt.figure()
nx.draw_networkx(G, with_labels=True)
plt.show()

plt.figure()
nx.draw_networkx(A, with_labels=True)
plt.show()

# user-defined functions utilization
print(find_path(G,'Shamakhi','Alat'))
calc_hours(G,'Kurdamir','Imishli')

print(find_path(A, 'PIT', 'RSW'))
print("distance =", calc_distance(A, 'PIT', 'RSW'))
print("time for flight =", calc_time(A, 'PIT', 'RSW'))
