import networkx as nx 

edges_nr = int(input("introduceti numarul de muchii: "))

G = nx.DiGraph()

path_l_s = ""

while path_l_s != "lung" or path_l_s != "scurt":
    print("Introduceti dupa modelul din paranteze (lung / scurt)")
    path_l_s = input("Cel mai lung sau cel mai scurt drum?(lung/scurt): ").lower()
    if path_l_s == "lung":
        for x in range(edges_nr):
            G.add_edge(int(input("Introduceti primnul nod: ")),int(input("introduceti nodul adicent: ")), weight = -abs(int(input("Introduceti ponderea: "))))
            x += 1
        length = dict(nx.all_pairs_bellman_ford_path_length(G))
        break
 
    elif path_l_s == "scurt":
        for x in range(edges_nr):
            G.add_edge(int(input("Introduceti primul nod: ")),int(input("introduceti nodul adicent: ")), weight = int(input("Introduceti ponderea: ")))
            x += 1
        length = dict(nx.all_pairs_bellman_ford_path_length(G))
        break

while True:
    x = int(input("introduceti nodul de start: "))
    y = int(input("Introduceti nodul de finis: "))
    while x and y not in G.nodes:
        print("nodurile nu fac parte din graf")
        x = int(input("introduceti nodul de start: "))
        y = int(input("Introduceti nodul de finis: "))
    
    if path_l_s == "lung":
        print("drumul maxim din {} in {} ".format(x,y))
        print(f" {x}-> {y}: {abs(length[x][y])}")
        pathnodes = dict(nx.all_pairs_bellman_ford_path(G))
        print(f"Drumul cel mai lung drum este \n{pathnodes[x][y]}")
        
        r = input("Doriti alte valori de start si finis? : ").capitalize()
    else:
        print("drumul minim din {} in {} ".format(x,y))
        print(f" {x}-> {y}: {length[x][y]}")
        print("Cele mai scurte drumuri")
        print([p for p in nx.all_shortest_paths(G,source=x,target=y,weight='weight')])
        r = input("Doriti alte valori de start si finis? : ").capitalize()
    
    if r == "Da":
        pass
    else :
        break