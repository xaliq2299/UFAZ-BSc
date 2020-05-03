from graph import Graph

E = Graph() # is_empty
S = Graph('A')
G = Graph('ABCDE')
G.add_edge('A','C')
G.add_edge('A','B')
G.add_edge('B','C')
G.add_edge('B','E')
G.add_edge('D','C')
G.add_edge('D','E')
P = Graph('xyz')
P.add_edge('z','y')
P.add_edge('x','y')
P.add_edge('y','x')
P.add_edge('x','x')
print('P', P.graph)
print('E', E.graph)
print('S', S.graph)
print('G', G.graph)

print("vertices\n", G.vertices())

# G.is_edge_unique(edge)
print("G edges", G.edges())

print("vertex A exists:", G.vertex_exists("A"))
print("vertex Z exists:", G.vertex_exists("Z"))
print("P edges", P.edges())

# G.get_vertex(label)
G.add_vertex("Z")
G.add_edge("Z", "A")
print("after Z-A\n", G.graph)

print("degree B:", G.degree("B"))

print('is empty, G:', G.is_empty(),
    '; E:', E.is_empty(),
    '; S:', S.is_empty(),
    '; P:', P.is_empty())
print('is null, G:', G.is_null(),
    '; E:', E.is_null(),
    '; S:', S.is_null(),
    '; P:', P.is_null())
print('is singleton, G:', G.is_singleton(),
    '; E:', E.is_singleton(),
    '; S:', S.is_singleton(),
    '; P:', P.is_singleton())
print('is trivial, G:', G.is_trivial(),
    '; E:', E.is_trivial(),
    '; S:', S.is_trivial(),
    '; P:', P.is_trivial())
print('is simple, G:', G.is_simple(),
    '; E:', E.is_simple(),
    '; S:', S.is_simple(),
    '; P:', P.is_simple())
print('is complete (Kn), G:', G.is_complete_Kn(),
    '; E:', E.is_complete_Kn(),
    '; S:', S.is_complete_Kn(),
    '; P:', P.is_complete_Kn())
print('has loop, G:', G.has_loop(),
    '; E:', E.has_loop(),
    '; S:', S.has_loop(),
    '; P:', P.has_loop())
print('has parallel, G:', G.has_parallel(),
    '; E:', E.has_parallel(),
    '; S:', S.has_parallel(),
    '; P:', P.has_parallel())
print('degree_centrality, G:', G.degree_centrality(),
    '; E:', E.degree_centrality(),
    '; S:', S.degree_centrality(),
    '; P:', P.degree_centrality())
print('network_density, G:', round(G.network_density(), 3),
    '; E:', round(E.network_density(), 3),
    '; S:', round(S.network_density(), 3),
    '; P:', round(P.network_density(), 3))
