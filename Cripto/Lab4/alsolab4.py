import collections
from collections import deque

#Key_p = input("Introduceti Key+ =>")
#while len(Key_p) != 56:
#    print("Cheia trebuie sa fie egala cu 56 de biti, introduceti cheia din nou")
#    Key_p = input("Introduceti Key+ =>")
 
Key_p = input("1111000 0110011 0010101 0101111 0101010 1011001 1001111 0001111")

key = Key_p.replace(" ","")

middle_index = len(key) // 2 
 
init_C_i = list[:middle_index] 
init_D_i = list[middle_index:]
    
C_i = collections.deque(init_C_i)
print(C_i)
D_i = collections.deque(init_D_i)
print(D_i)
i = int(input("Dati i (1<=i<=16) pentru Ci si Di dorit: (1<=i<=16)"))
for a in range (1,i):
    if (i==1 or i==2 or i==9 or i==16):
        changed_C_i = C_i.rotate(-1)
        changed_D_i = D_i.rotate(-1)
    else: 
        changed_C_i = C_i.rotate(-2)
        changed_D_i = D_i.rotate(-1)

print(changed_C_i)
print(changed_D_i)
