import networkx as nx 
import matplotlib.pyplot as plt

edges_nr = int(input("Introduceti numarul de muchii=>"))

G = nx.DiGraph()

path = ""

while path != "maxim" or path != "minim":
    print("Introduceti dupa modelul din paranteze (maxim / minim)")
    path = input("Drumul minim sau maxim?(maxim/minim): ").lower()

    if  path == "minim":
        for x in range(edges_nr):
            G.add_edge(int(input("Primnul nod=>")),
                       int(input("Nodul adicent=>")), 
                       weight = int(input("Ponderea=>")))
            x += 1
 
    elif path == "maxim":
        for x in range(edges_nr):
            G.add_edge(int(input("Primnul nod=>")),
                       int(input("Nodul adicent=>")), 
                       weight = -abs(int(input("Ponderea=>"))))
            x += 1

    length = dict(nx.all_pairs_bellman_ford_path_length(G))
    pos = nx.circular_layout(G)
    nx.draw_networkx(G, pos)
    labels = nx.get_edge_attributes(G, ('weight'))
    nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)
    plt.show()
    break

x = int(input("Nodul de start: "))
y = int(input("Ultimul nod: "))


if path == "maxim":
    print("Drumul maxim din {} in {} ".format(x,y))
    print(f" {x}-> {y}: {abs(length[x][y])}")
    pathnodes = dict(nx.all_pairs_bellman_ford_path(G))
    print(f"Drumul cel mai lung drum este \n{pathnodes[x][y]}")
    

else:
    print("Drumul minim din {} in {} ".format(x,y))
    print(f" {x}-> {y}: {length[x][y]}")
    print("Cele mai scurte drumuri")
    print([p for p in nx.all_shortest_paths(G,source=x,target=y,weight='weight')])