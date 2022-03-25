import numpy as np

alphabet = "AĂÂBCDEFGHIÎKLMNOPQRSȘTȚUVWXYZ"

def Criptare():
    message = input("Mesajul => ").upper()
    message = message.replace(" ","")

    key = input("Cheia => ").upper()
    key = key.replace(" ","")
    cripted = ""

    key1=key


    while (len(key)<=len(message)):
        key+=key1
    key = key[0: len(message)]

    print(message,"\n")
    print(key,"\n")

    for i in range(0,len(message)):
        position_m = alphabet.find(message[i])
        position_k = alphabet.find(key[i])
        position_c = (position_m + position_k) % 31
        cripted += alphabet[position_c]

    print(cripted)

def Decriptare():
    cripted = input("Mesajul criptat => ").upper()
    cripted = cripted.replace(" ","")

    key = input("Cheia => ").upper()
    key = key.replace(" ","")
    message = ""

    key1=key

    while (len(key)<=len(cripted)):
        key+=key1
    key = key[0: len(cripted)]

#    print(cripted)
#    print(key)

    for i in range(0,len(cripted)):
        position_c = alphabet.find(cripted[i])
        position_k = alphabet.find(key[i])
        position_m = (position_c - position_k) % 31
        message += alphabet[position_m]
    print(message)

menu=input("""
1-Criptare
2-Decriptare
0-Exit
""")

match menu:
    case "1":
        Criptare()
    case "2":
        Decriptare()