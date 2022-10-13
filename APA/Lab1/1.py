import time
import scipy.constants
import math
import matplotlib.pyplot as plt

def fibonacci_iter(pos):
    iter = 0
    nr1 = 1
    nr2 = 1
    f_nr = 0
    if pos == 1 or pos == 2:
        return nr1, iter
    else:
        t0 = time.process_time()
        for i in range(3, pos+1):
            iter =+ 1
            f_nr = nr1 + nr2
            nr1 = nr2
            nr2 = f_nr
        t = time.process_time() - t0
        return f_nr, iter, t
for i in range(3,15):
       a,b,c=fibonacci_iter(i)
       print(a,b,c)