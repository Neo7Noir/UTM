import networkx as nx 

edges_nr = int(input("Dati numarul de muchii=>"))

G = nx.DiGraph()

path = ""

while path != "maxim" or path != "minim":
    print("Drumul: maxim/minim")

    path = input("Ce tip de drum doriti? (maxim/minim)=>").lower()
    if path == "minim":
        for x in range(edges_nr):
            G.add_edge(int(input("Introduceti primul nod=>")),
                       int(input("Introduceti nodul adicent=>")), 
                       weight = int(input("Introduceti ponderea=>")))
            x += 1
        length = dict(nx.all_pairs_bellman_ford_path_length(G))
        break 

    elif path == "maxim":
        for x in range(edges_nr):
            G.add_edge(int(input("Introduceti primul nod=>")),
                       int(input("Introduceti nodul adicent=>")), 
                       weight = -abs(int(input("Introduceti ponderea=>"))))
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
    
    if path == "maxim":
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