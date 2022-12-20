import sympy as sym
import matplotlib.pyplot as plt
import csv

eps = 10 ** -4

def export(rows):
    with open(f"var_{var}.csv", 'w') as f:
        csv.writer(f).writerows(rows)

def print_points(x,y):
    for x,y in zip(x,y):
        print(f'({x}, {y})')

def print_function(f):
    print("Polinomul lagrange:")
    print(f"L{sym.degree(f)} = {str(f).replace('**','^')}")



def lagrange(x, y):
    v = sym.Symbol('x')
    lagrange = 0
    for i in range(len(x)):
        Ln = y[i]
        for j in range(len(x)):
            if j == i:
                continue
            Ln *= (v - x[j])/(x[i] - x[j])
        lagrange += Ln
    lagrange = sym.simplify(lagrange).evalf()
    return lagrange

def L_n(x0, x1, y0, y1):
    return (y0 * x1 - y1 * x0)/(x1-x0)

def aitken(a, x, y):
    headers = ["Xi", "Yi", "Xi - a"]
    tabel = []
    for i in range(len(x)):
        line = [x[i], y[i], round(x[i] -a,5)]
        title = "L_"
        for j in range(i,0,-1):
            if i == 0:
                continue
            title += f'i-{j}_'
            line.append(0)
        if i != 0:
            headers.append(title+'i')
        tabel.append(line)

    val = 0
    error = 0
    for i in range(len(tabel)):
        for j in range(1, len(tabel[i])):
            try:
                x0, x1, y0, y1 = tabel[i-j+2][2], tabel[i][2], tabel[i-1][j-2], tabel[i][j-2]
            except:
                pass
            if j > 3:
                y0 = tabel[i-1][j-1]
                y1 = tabel[i][j-1]
            if tabel[i][j] == 0:
                val = L_n(x0, x1, y0, y1)
                tabel[i][j] = round(val, 4)

            error = abs(tabel[i][j] - tabel[i-1][j-1]) 
            if error < eps:
                break
    
    print('\n'.join(['|'.join(['{:10}'.format(item) for item in row]).replace("_",",") +"|" for row in [headers]+tabel]))
    export([headers]+tabel)
    print("error:", error)
    print(f'f({a})≈L({a})= {val}')
    return val

var = 23
a = 1.276
x = [0.765, 1.867, 3.987, 5.601, 7.043, 9.231, 10.987]
y = [2.87611, 4.18432, 1.09673, -1.4587, -3.5729, 0.9876, 2.87644]


f = lagrange(x, y)
print(f"L{sym.degree(f)}({a}) = {f.subs('x', a)}")
print_function(f)

aitken(a, x, y)