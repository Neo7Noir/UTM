import pdb
from random import randint


max = []
sumMax = 0

def calc(n, currNivel, nivel, pondereSum, tempMax, i):
    global sumMax
    global max
    pdb.set_trace()
    print(currNivel, " ", nivel,"",i)
    print(type(currNivel),"",type(nivel))
    print(currNivel == nivel)
    if currNivel == nivel:
        if(pondereSum > sumMax):
            sumMax = pondereSum
            #max = tempMax
        return 0

    for i in range(1,n+1):
        #tempMax.append(i*currNivel)
        pondereSum += randint(0,100)
        currNivel += 1
        calc(n, currNivel, nivel, pondereSum, tempMax, i)
        #tempMax.pop(len(tempMax) - 1)

calc(3, 0, 5, randint(0,100), [], 0)