
alf = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
meni=int(input("""
1-Criptare
2-Decriptare
3-Criptare prin permutari
0-Exit
"""))
if meni==1:
    print("Criptarea:")
    key = int(input('Key-> '))
    message = input("Mesajul-> ").upper()
    itog = ''
    for i in message:
        mesto = alf.find(i)
        new_mesto = mesto + key
        if i in alf:
            itog += alf[new_mesto]
        else:
            itog += i
elif meni==2:
    print("Decriptarea:")
    key_d = int(input('Key-> '))
    message = input("Mesajul criptat->").upper()
    itog = ''
    for i in message:
        mesto = alf.find(i)
        new_mesto = mesto - key_d
        if i in alf:
            itog += alf[new_mesto]
        else:
            itog += i
elif meni==3:
    print("Criptarea cu permutari:")
    word_p = input("Cuvintul pentru permutari(Totul cu majuscule)->").upper()
    key_p = int(input('Key-> '))
    message = input("Mesajul->").upper()
    alf_p = ''
    for i in word_p:
        alf_p += i.upper()
        # print(i)
        alf = str.replace(alf, i, '')
    print(alf)
    alf_r = alf_p + alf
    print("Alfabetul pentrumermutari->", alf_r)
    itog = ''
    for i in message:
        mesto = alf_r.find(i)
        new_mesto = mesto + key_p
        if i in alf:
            itog += alf_r[new_mesto]
        else:
            itog += i
elif meni==4:
    print("Criptarea cu permutari:")
    word_p = input("Cuvintul pentru permutari(Totul cu majuscule)->").upper()
    key_p = int(input('Key-> '))
    message = input("Mesajul criptat->").upper()
    alf_p = ''
    for i in word_p:
        alf_p += i.upper()
        # print(i)
        alf = str.replace(alf, i, '')
    print(alf)
    alf_r = alf_p + alf
    print("Alfabetul pentrumermutari->", alf_r)
    itog = ''
    for i in message:
        mesto = alf_r.find(i)
        new_mesto = mesto - key_p
        if i in alf:
            itog += alf_r[new_mesto]
        else:
            itog += i
else:
    print("Exit:")
    sys.exit()
print(itog)
