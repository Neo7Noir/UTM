#1 clase si obiecte suprafata cercului, volumul sferei cu aceeasi raza si adunarea numarului rezultatului
#2 lista de numere de la 0 la 1000 de afisat toate polidroamele
from math import pi

class Cerc:
    def __init__(self, raza):
        self.raza = raza

    def suprafata_cercului(self):
        suprafata = pi * self.raza ** 2
        return suprafata
    def volumul_sferei(self):
        volumul = (4 * pi * self.raza ** 3) / 3
        return volumul


cerc = Cerc(8)
print("Suprafata cercului",cerc.suprafata_cercului(),"m^2")
print("Volumul sferei",cerc.volumul_sferei(),"m^3")
print("Rezultatul adunarii: ",cerc.volumul_sferei() + cerc.suprafata_cercului())


l=[x for x in range (0, 1001)]

print("Palindroamele sunt:")
for i in l:
    num=str(i)
    if("".join(reversed(num))==num):
        print(i)