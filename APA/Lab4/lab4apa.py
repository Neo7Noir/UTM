import random

def createGraf(varf, dens):
    G = [[0] * varf] * varf

    for i in range(varf):
        for j in range(varf):
            if (j > i):
                r = random.randint(0,100)

                if(r <= dens):
                    r = random.randint(1,10000)
                    G[i][j] = r
                else:
                    G[i][j] = G[j][i]

    for i in range(varf):
        for j in range(varf):
            if(G[i][j] == 0 and i != j):
                G[i][j] = 99999

    return G

def floyd(G,nV):
    iter = 0
    distance = list(map(lambda i: list(map(lambda j: j, i)), G))

    for k in range(nV):
        for i in range(nV):
            for j in range(nV):
                iter += 1
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])

    print("Floyd Iteratii",iter)

iterdijkstra = 0

def minCost(cost, visited, V):
    global iterdijkstra
    min = 99999
    minIndex = 0

    for i in range(V):
        iterdijkstra += 1
        if(visited[i] == 0 and cost[i] <= min):
            iterdijkstra += 1
            min = cost[i]
            minIndex = i

    return minIndex


def dijkstra(G, V):
    global iterdijkstra

    for i in range(V):
        cost = [99999] * V
        visited = [0] * V

        cost[i] = 0

        for i in range(V - 1):
            min = minCost(cost, visited, V)

            visited[min] = 1
            for j in range(V):
                iterdijkstra += 1
                if(visited[j] == 0 and G[min][j] != 0 and cost[min] != 99999 and (cost[min] + G[min][j] < cost[j])):
                    iterdijkstra += 1
                    cost[j] = cost[min]+G[min][j]

    print("Dijkstra Iteratii : ",iterdijkstra)

varf = [10,15,20]
dens = [20,50,100]

for i in dens:
    for j in varf:
        print("Varfuri:",j,"Densitatea:",i)
        G = createGraf(j,i)
        floyd(G,j)
        dijkstra(G,j)