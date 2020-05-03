import pandas as pd
import networkx as nx
import numpy as np
import io
import matplotlib.pyplot as plt
from google.colab import files

#Edmonds-Karp
def max_flow(C, s, t): # s stands for source, t for target
        n = len(C) # C is the capacity matrix
        F = [[0] * n for i in range(n)]
        path = bfs(C, F, s, t)
        while path != None:
            flow = min(C[u][v] - F[u][v] for u,v in path)
            for u,v in path:
                F[u][v] += flow
                F[v][u] -= flow
            path = bfs(C, F, s, t)
        return sum(F[s][i] for i in range(n))

#Breadth First Search
def bfs(C, F, s, t):
        queue = [s]
        paths = {s:[]}
        if s == t:
            return paths[s]
        while queue: 
            u = queue.pop(0)
            for v in range(len(C)):
                    if(C[u][v]-F[u][v]>0) and v not in paths:
                        paths[v] = paths[u]+[(u,v)]
                        #print(paths)
                        if v == t:
                            return paths[v]
                        queue.append(v)
        return None


uploaded = files.upload() # was important to load files while working with Colab
data_cities = io.BytesIO(uploaded['sample_network.csv']) # to read files
data = pd.read_csv('sample_network.csv')

G=nx.from_pandas_edgelist(data, source='Source', target='Sink', edge_attr=True)

# visualizing the graph
plt.figure()
nx.draw_networkx(G, with_labels=True)
plt.show()

print(nx.betweenness_centrality(G, weight='Kpbs_AVG'))
print(nx.density(G))
print(nx.diameter(G))
print(nx.average_shortest_path_length(G))
print(nx.closeness_centrality(G))
print(nx.average_degree_connectivity(G))


# Building Capacity adjacent matrix
C=np.zeros((101,101))
# print(len(data))
for i in range(len(data)):
  #print(data.iloc[i,0], data.iloc[i,1], data.iloc[i,2])
  C[data.iloc[i,0]][data.iloc[i,1]]=data.iloc[i,2]
#print(C)


source = 100
target = 54
flow = max_flow(C, source, target)
print("max_flow_value is: ", flow)