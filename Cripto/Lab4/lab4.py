Key_p = input("Introduceti Key+ =>")
Key_p = Key_p.replace(" ","")
while len(Key_p) != 56:
    print("Cheia trebuie sa fie egala cu 56 de biti, introduceti cheia din nou")
    Key_p = input("Introduceti Key+ =>")



#Key_p = "11110000110011001010101011110101010101100110011110001111"

list = list(Key_p) 
 
length = len(list) 
 
middle_index = length // 2 
 
C = list[:middle_index] 
D = list[middle_index:] 
 
print(C) 
print(D)

i = int(input("Dati i (1<=i<=16) pentru Ci si Di dorit: (1<=i<=16)"))
for a in range (1,i):
    if (i==1 or i==2 or i==9 or i==16):
        C.append(C.pop(0))
        D.append(D.pop(0))
    else: 
        C.append(C.pop(0))
        C.append(C.pop(0))
        D.append(D.pop(0))
        D.append(D.pop(0))

print(C) 
print(D)