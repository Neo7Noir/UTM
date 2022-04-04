import networkx as nx
import matplotlib.pyplot as plot

G = nx.DiGraph

G = nx.read_edgelist("graph5.txt", nodetype=int, data=(("capacity", int),))
pos = nx.circular_layout(G)
nx.draw_networkx(G, pos)
labels = nx.get_edge_attributes(G, 'capacity')
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)
nx.draw_networkx_edges(G,pos,edgelist = labels, arrows=True)
plot.show()


x = int(input("Nodul de start=>"))
y = int(input("Nodul de finis=>"))

flow_value = nx.maximum_flow(G, x, y)
print(f"Capacitatea maxima pe graf este {flow_value}")