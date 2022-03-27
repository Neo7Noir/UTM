import numpy as np
import random

alphabet='AĂÂBCDEFGHIÎKLMNOPQRSȘTȚUVWXYZ'
inlocuire ='QVXZ'

menu=int(input("""
1-Criptare
2-Decriptare
0-Exit
"""))


def Criptare():
    message = input("Mesajul => ").upper()
    message = message.replace(" ","")

    def verificare():
        for i in range(0, len(message)):
            if message[i] not in alphabet:
                return False 
        return True


    while verificare() == False:
        print("Unele caractere introduse nu sunt din alfabetul roman!")
        print("Introduceti inca o data dar in diapazonul alfabetului roman: AĂÂBCDEFGHIÎKLMNOPQRSȘTȚUVWXYZ")
        message = input("Mesaj =>").upper()
        verificare()



    def replacedChar():
        prev = ''
        res = ''

        res = inlocuire[random.randint(0, len(inlocuire) - 1)]
        while res == prev:
            res = inlocuire[random.randint(0, len(inlocuire) - 1)]
        prev = res
        return res


    for i in range(len(message)):
        if(message[i] == message[i - 1] and message[i+1] == message[i]):
            message = message[:i] + replacedChar() + message[i:]
            message = message[:i+2] + replacedChar() + message[i+2:]
            
    message = " ".join(message[i:i+2] for i in range(0, len(message), 2))

    for i in range(len(message)):
        if(message[i] == message[i - 1]):
            message = message[:i] + replacedChar() + message[i:]
            message = message[:i+1] + ' ' + message[i+1:]

    message = message.replace(" ","")
    if (len(message) % 2 != 0):
        message = message[0: len(message)-1]    
    message = " ".join(message[i:i+2] for i in range(0, len(message), 2))

    print(message)


    key = input("key => ").upper()
    key = key.replace(" ","")

    while len(key)<7:
        print("Lungimea cheii este pea mica, necesita sa fie lungimea nu mai mica de 7")
        key = input("Key =>").upper()

    matrix_6x5 = [[0 for i in range (6)] for j in range(5)]
    need_alph = ''.join(dict.fromkeys(key + alphabet))


    index = 0
    for i in range(0,5):
        for j in range(0,6):

            matrix_6x5[i][j] = need_alph[index]
            index+=1




    for i in matrix_6x5:
        print(i)

    def indexLocator (char):
        indexOfChar = []
        for i,j in enumerate(matrix_6x5):
            for k,l in enumerate(j):
                if char == l:
                    indexOfChar.append(i) 
                    indexOfChar.append(k)
                    return indexOfChar

    message = message.replace(" ","")

    cipherText = []

    i = 0
    while i < len(message):

        n1 = indexLocator(message[i])
        n2 = indexLocator(message[i+1])



        if (n1[1] == n2[1]):

            i1 = (n1[0] + 1) % 5
            j1 = n1[1]

            i2 = (n2[0] + 1) % 5
            j2 = n2[1]
            cipherText.append(matrix_6x5[i1][j1])
            cipherText.append(matrix_6x5[i2][j2])


        elif (n1[0]==n2[0]):
            i1= n1[0]
            j1= (n1[1] + 1) % 6


            i2= n2[0]
            j2= (n2[1] + 1) % 6
            cipherText.append(matrix_6x5[i1][j1])
            cipherText.append(matrix_6x5[i2][j2])



        else:
            i1 = n1[0]
            j1 = n1[1]

            i2 = n2[0]
            j2 = n2[1]

            cipherText.append(matrix_6x5[i1][j2])
            cipherText.append(matrix_6x5[i2][j1])


        i += 2  

    def listToString(): 
        
        str1 = "" 
    
        for ele in cipherText: 
            str1 += ele 
        str1 = " ".join(str1[i:i+2] for i in range(0, len(str1), 2)) 
        
        return str1

    print(listToString()) 


def Decriptare():
    message = input("Textul criptat => ").upper()
    message = message.replace(" ","")


    message = " ".join(message[i:i+2] for i in range(0, len(message), 2))



    key = input("key => ").upper()
    key = key.replace(" ","")

    while len(key)<7:
        print("Lungimea cheii este pea mica, necesita sa fie lungimea nu mai mica de 7")
        key = input("Key =>").upper()

    matrix_6x5 = [[0 for i in range (6)] for j in range(5)]
    need_alph = ''.join(dict.fromkeys(key + alphabet))


    index = 0
    for i in range(0,5):
        for j in range(0,6):

            matrix_6x5[i][j] = need_alph[index]
            index+=1




    for i in matrix_6x5:
        print(i)

    def indexLocator (char):
        indexOfChar = []
        for i,j in enumerate(matrix_6x5):
            for k,l in enumerate(j):
                if char == l:
                    indexOfChar.append(i) 
                    indexOfChar.append(k)
                    return indexOfChar

    message = message.replace(" ","")

    cipherText = []

    i = 0
    while i < len(message):

        n1 = indexLocator(message[i])
        n2 = indexLocator(message[i+1])



        if (n1[1] == n2[1]):

            i1 = (n1[0] - 1) % 5
            j1 = n1[1]

            i2 = (n2[0] - 1) % 5
            j2 = n2[1]
            cipherText.append(matrix_6x5[i1][j1])
            cipherText.append(matrix_6x5[i2][j2])


        elif (n1[0]==n2[0]):
            i1= n1[0]
            j1= (n1[1] - 1) % 6


            i2 = n2[0]
            j2 = (n2[1] - 1) % 6
            cipherText.append(matrix_6x5[i1][j1])
            cipherText.append(matrix_6x5[i2][j2])



        else:
            i1 = n1[0]
            j1 = n1[1]

            i2 = n2[0]
            j2 = n2[1]

            cipherText.append(matrix_6x5[i1][j2])
            cipherText.append(matrix_6x5[i2][j1])


        i += 2  

    def listToString(): 
        
        str1 = "" 
    
        for ele in cipherText: 
            str1 += ele  
        
        str1 = str1.replace("Q","")
        str1 = str1.replace("V","")
        str1 = str1.replace("X","")
        str1 = str1.replace("Z","")
        

        return str1

    print(listToString()) 

match menu:
    case 1:
        Criptare()
    case 2:
        Decriptare()