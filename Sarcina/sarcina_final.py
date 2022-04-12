import time
from random import randint

maxN = [[]]
sumMax = 0
currNode = 1

def calc(n, currNivel, nivel, pondereSum, tempMax):
    global sumMax
    global maxN
    global currNode 

    if currNivel >= nivel:
        if pondereSum >= sumMax:
            sumMax = pondereSum
            maxN = tempMax.copy()
        return

    for i in range(1,n+1):
        pond = randint(0,100)
        currNode = currNode + 1
        tempMax.append([currNode,pond])
        calc(n, currNivel+1, nivel, pondereSum + pond, tempMax)
        tempMax.pop(len(tempMax) - 1)

start = time.time()
a = randint(0,100)
calc(2, 1, 20, 0, [[currNode,0]])
end = time.time()
print(sumMax,"",end-start)
print(maxN)