import pandas as pd
import networkx as nx
import numpy as np
from collections import deque

def dijkstra(g,source,target,weight):
    queue=deque()
    dist={}
    for i in g:
        dist[i]=float("Inf")

    dist[source]=0
    queue.append(source)
    while queue:
        current=queue.popleft()
        if current==target:
            return dist[target]
                dist[i] = dist[current] + g.edges[current, i][weight]
        for i in  g.neighbors(current):
            if dist[i]>dist[current]+g.edges[current,i][weight]:

                queue.append(i)
    return None

def belmanFord(g,source,target,weight):
    dist={}
    pred={}
    for i in g:
        dist[i]=float("Inf")
        pred[i]=None

    dist[source]=0
    for i in range(len(g.nodes())):
        for j in g:
            for neig in g.neighbors(j):
                if dist[neig]+g.edges[j,neig][weight]<dist[j]:
                    dist[j]=dist[neig]+g.edges[j,neig][weight]
		    pred[j]=neig
    return dist[target]


#uploaded = files.upload() # was important to load files while working with Colab
#data_cities = io.BytesIO(uploaded['cities_in_az.csv']) # to read files
data_cities = pd.read_csv('cities_in_az.csv')

G=nx.from_pandas_edgelist(data_cities, source='Origin', target='Destiny', edge_attr=True)

# visualizing the graph
plt.figure()
nx.draw_networkx(G, with_labels=True)
plt.show()

(dijkstraG,'Baku','Kurdamir','Hours')
