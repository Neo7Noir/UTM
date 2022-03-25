import numpy as np
import os

vizitate = []

def Adancimea(vizitate,lista,nodul):
    nodul-=1
    if nodul not in vizitate:
        print(nodul+1, end = " ")
        vizitate.append(nodul)
        for recurs in lista[nodul][0: len(lista[nodul])-1]:
            Adancimea(vizitate,lista,recurs)

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
Adancimea(vizitate,lista,init)