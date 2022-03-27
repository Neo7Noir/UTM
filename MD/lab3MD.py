import numpy as np

vizitate = []

def Largimea(lista, initial):
    vizitat = []
    asteptare = []

    print("\nParcurgerea in largime a grafului este : ", end='')

    vizitat.append(initial - 1)
    asteptare.append(initial - 1)

    while asteptare:
        nod = asteptare.pop(0)
        print(nod + 1, end =' ')

        for vecini in lista[nod][0:len(lista[nod]) - 1]:
            if vecini - 1 not in vizitat:
                vizitat.append(vecini - 1)
                asteptare.append(vecini - 1)

#citire lista
def citireLista():
    nods = int(input("Cate noduri are matricea? "))
    lista = np.zeros(nods, dtype = object)
    for i in range(0, nods):
        l = []
        n = int(input("Cate legaturi sunt pentru nodul " + str(i+1) + ":"))
        if (n != 0):
            l = list(map(int,input("Dati legaturile : ").strip().split()))[:n]
            while not all(i <= nods for i in l):
                print("Date introduse gresit.")
                l = []
                l = list(map(int,input("Dati legaturile : ").strip().split()))[:n]
        l.append(0)
        lista[i] = l

    return lista

#afisare lista
def afisareLista(lista):
    nods = lista.shape[0]
    print("Lista adiacenta:")
    for i in range(1,nods+1):
        print(i,'- ',end='')
        for j in lista[i-1]:
            if(j != 0):
                print(str(j)+'_',end = '')
            else:
                print(j)

lista = citireLista()
afisareLista(lista)
init = int(input("Introduceti nodul initial =>"))
Largimea(lista,init)