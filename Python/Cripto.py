alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ"
result = ''

menu=int(input("""
1-Criptare
2-Decriptare
3-Criptare prin permutari
4-Decriptare prin permutari
0-Exit
"""))
##Criptare
if menu == 1:
    message = input("Mesajul => ").upper()
    message = message.replace(" ","")
    key = int(input("Cheia => "))
    for i in message:
        position = alphabet.find(i)
        new_position = position + key
        result += alphabet[new_position]
    print(result)

#Decriptare
elif menu == 2:
    message = input("Mesajul criptat => ").upper()
    message = message.replace(" ","")
    key = int(input("Cheia => "))
    for i in message:
        position = alphabet.find(i)
        new_position = position - key
        result += alphabet[new_position]
    print(result)
    
#Criptare prin permutari
elif menu == 3:
    init_p_word = input("Cuvantul pentru permutare => ").upper()
    init_p_word = init_p_word.replace(" ","")
    p_word = "".join(dict.fromkeys(init_p_word))  #stergem aceleasi caractere in cuv 
    
    message = input("Mesajul => ").upper()
    message = message.replace(" ","")
    key = int(input("Cheia => "))

    alphabet_p = ''
    for i in p_word:
        alphabet_p += i
        alphabet = alphabet.replace(i,'')
    f_alphabet = alphabet_p + alphabet
    print("Alfabetul permutat => " + f_alphabet)
    for i in message:
        position = f_alphabet.find(i)
        new_position = position + key
        result += f_alphabet[new_position]
    print(result)    

elif menu == 4:
    init_p_word = input("Cuvantul pentru permutare => ").upper()
    init_p_word = init_p_word.replace(" ","")
    p_word = "".join(dict.fromkeys(init_p_word))  #stergem aceleasi caractere in cuv 
    
    message = input("Mesajul => ").upper()
    message = message.replace(" ","")
    key = int(input("Cheia => "))

    alphabet_p = ''
    for i in p_word:
        alphabet_p += i
        alphabet = alphabet.replace(i,'')
    f_alphabet = alphabet_p + alphabet
    #print("Alfabetul permutat => " + f_alphabet)
    for i in message:
        position = f_alphabet.find(i)
        new_position = position - key
        result += f_alphabet[new_position]
    print(result)  