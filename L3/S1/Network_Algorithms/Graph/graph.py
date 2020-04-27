class Graph:
	def __init__(self,nVertices):
		self.graph={}
		for i in range(nVertices):
			self.graph[i]=[]
			self.nVertices=nVertices

	def print_graph(self):
		print(self.graph)

	def add_vertex(self,id): # id stands for label for a vertex (dictionary key)
		self.graph[id]=[]
		self.nVertices += 1

	def	add_edge(self,A,B): # A and B are vertices
		if A not in self.graph[B]:
			self.graph[B].append(A)
		if B not in self.graph[A]:
			self.graph[A].append(B)

	def degree(self,vertex): # loops x2
		print("degree(vertex="+str(vertex)+")=")
		d=len(self.graph[vertex])
		return d+1 if vertex in self.graph[vertex] else d

	def is_empty(self):	
		for i in range(self.nVertices):
			if self.graph[i]:
				return False
		return True

def main():
	G=Graph(5)
	G.graph[0].append(1)
	G.print_graph()
	#G.add_vertex(4)
	#G.print_graph()
	G.add_vertex(0)
	#G.print_graph()
	#G.add_vertex(-1)
	G.print_graph()
	#G.add_vertex('A')
	#G.print_graph()
	G.add_edge(0,1)
	G.add_edge(0,4)
	G.add_edge(1,4)
	G.add_edge(1,3)
	G.add_edge(4,3)
	G.add_edge(3,4)
	G.add_edge(1,2)
	G.add_edge(2,3)
	#G.add_edge(0,0)
	G.print_graph()
	#print(G.degree(0))
	#print(G.degree(1))
	#print(G.degree(2))
	#print(G.degree(3))
	#print(G.degree(4))
	print(G.is_empty())
	G0=Graph(4)
	print(G0.is_empty())
	# at this point we finally have the full graph that we needed

if __name__ == "__main__":
	main()
