from time import perf_counter_ns
import scipy.constants
import math
import matplotlib.pyplot as plt

fi = scipy.constants.golden_ratio

#functia pentru metoda iterativa
def fibonacci_iter(pos):
    iter = 0
    nr1 = 1
    nr2 = 1
    f_nr = 0
    if pos == 1 or pos == 2:
        return nr1, iter
    else:
        t0 = perf_counter_ns()
        for i in range(3, pos+1):
            iter += 1
            f_nr = nr1 + nr2
            nr1 = nr2
            nr2 = f_nr
        t = (perf_counter_ns() - t0)*10**(-6)
        return f_nr, iter, t

#functia pentru metoda recursiva
def fibonacci_rec(pos):
    global iter1 
    
    iter1 += 1
    if pos <= 1:
        return pos
    else:
        return fibonacci_rec(pos - 1) + fibonacci_rec(pos - 2)
iter1=0



#functia pentru metoda formulei
def function_fibonacci(pos,phib):
    return round(((phib**pos) - ((1 - phib) ** pos))/math.sqrt(5), 0)



nr_posFib = int(input("Pozitia nr Fibonacci: "))
print("Metoda iterativa:")
a,b,c=fibonacci_iter(nr_posFib)
print("Nr fibonacci: ", a)
print("Numarul de iteratii: ", b)
print("Timpul de executie: ", c,"s")

print("Metoda recursiva:")
t0 = perf_counter_ns()
print("Nr Fibonacci: ", fibonacci_rec(nr_posFib))
t = (perf_counter_ns() - t0)*10**(-9)
print("Numarul de iteratii: ", iter1)
print("Timpul de executie: ",t,"s")

print("Metoda formulei:")
start = perf_counter_ns()
print("Nr Fibonacci: ", function_fibonacci(nr_posFib, fi))
end = (perf_counter_ns() - start)*10**(-9)
print("Nr de iteratii: 1")
print("Timpul de executie: ", end,"s")



#Afisarea cu Matplotlib
l_iter=[1, 1]
for i in range(3,30,3):
    a, b, c = fibonacci_iter(i)
    l_iter.append(b)

l=[]
l_recur=[]
for i in range(1,30,3):
    l.append(i)
    fibonacci_rec(i)
    l_recur.append(iter1)

# print(l_recur)
# print(l_iter)

l_form = []
for i1 in range(1,15):
    l_form.append(1)
#print(l_form)

nr_elem=int(input("Cate elemente de depus in grafic? "))
plt.plot(l[:nr_elem], l_iter[:nr_elem])
plt.plot(l[:nr_elem], l_recur[:nr_elem])
plt.plot(l[:nr_elem], l_form[:nr_elem])
plt.legend(["Iterativa", "Recursiva", "Formula"])
plt.xlabel('Fibonacci numbers')
plt.ylabel('Iterations')
plt.show()