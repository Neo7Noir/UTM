from asyncore import ExitNow
from audioop import add
import sys
def Cezar_e():
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    string_input = (input("introduceti un cuvant: ")).upper()
    key = int(input("Introduceti cheia(1->25): "))
    input_lenght = len(string_input)
    string_en = ""
    for i in range(input_lenght):
        character = string_input[i]
        location_of_character = alphabet.find(character)
        new_location = (location_of_character + key) % 26
        string_en += alphabet[new_location]

    print(string_en)

def Cezar_de():
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    string_input = (input("introduceti mesajul: ")).upper()
    key = int(input("Introduceti cheia(1->25): "))
    input_lenght = len(string_input)
    string_dec = ""
    for i in range(input_lenght):
        character = string_input[i]
        location_of_character = alphabet.find(character)
        og_location = (location_of_character - key) % 26
        string_dec += alphabet[og_location]
    print(string_dec)

def Cezar_word_e():
    clear_text = input("introduceti mesajul: ").upper()
    valid_letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    user_key = input("introduceti cuvantul cheie : ").upper()
    key = ""
    nr_key = int(input("introduceti un numar: "))
    string_en = ""
    new_string = ""
    string_dec = ""
    cipher_text = []

    for char in clear_text:
        if char in valid_letters:
            new_string += char

    for char in user_key:
        if char in valid_letters:
            if char not in key:
                key += char

    for char in valid_letters:
        if char not in key:
            key += char

    for i in range(len(clear_text)):
        character = clear_text[i]
        location_of_character = key.find(character)
        new_location = (location_of_character + nr_key) % 26
        string_en += key[new_location]
    print(string_en)

def Cezar_word_de():
    clear_text = input("introduceti mesajul: ").upper()
    valid_letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    user_key = input("introduceti cuvantul cheie : ").upper()
    key = ""
    nr_key = int(input("introduceti un numar: "))
    string_en = ""
    new_string = ""
    string_dec = ""
    cipher_text = []

    for char in clear_text:
        if char in valid_letters:
            new_string += char

    for char in user_key:
        if char in valid_letters:
            if char not in key:
                key += char

    for char in valid_letters:
        if char not in key:
            key += char
    for i in range(len(clear_text)):
        character = clear_text[i]
        location_of_character = key.find(character)
        og_location = (location_of_character - nr_key) % 26
        string_dec += key[og_location]
    print(string_dec)





def quit():
    print("iesire")
    sys.exit()



def menu():
    print("\n*******Meniul principal*******")

    choice = input("""
    
    1: Cezar encriptarea
    2: Cezar decriptarea
    3: Cezar + cuvant encriptarea
    4: Cezar + cuvant decriptarea
    0: Iesirea din meniu

    Alegeti o optiunea

    """)

    if choice == "1":
        Cezar_e()
    elif choice == "2":
        Cezar_de()
    elif choice == "3":
        Cezar_word_e()
    elif choice =="4":
        Cezar_word_de()
        
    elif choice == "0":
        quit()
    else :
        print("alegerea nu este din meniu")
        menu()

menu()