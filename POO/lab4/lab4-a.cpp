#include <iostream>
#include <string>

using namespace std;

class Carte;
class Caiet;
class Caiet_notite;

class Carte{
private:
    string denumirea;
    string autorul;
public:
    Carte(string denum, string aut){
        denumirea = denum;
        autorul = aut;
    }

    void citire(){
        cout << "Denumirea: " << denumirea << endl;
        cout << "Autorul: " << autorul << endl;
    }
};

class Caiet{   
private:
    string continut;
public:
    Caiet(string cont){
        continut = cont;
    }
    void scrie(){
        cout << "Introduceti continutul: " << endl;
        cin >> continut;
    }
    friend class caiet_de_notite;
};

class caiet_de_notite: public Carte, public Caiet{
public:
    caiet_de_notite(string denum, string aut, string cont):Carte(denum, aut), Caiet(cont){
        
    }

    void citire(){
        Carte::citire();
        cout << "Continutul: " << continut << endl;    }
};


int main(){
caiet_de_notite c("Petrea", "Vasile Romanciuk", "continutul initial");
c.citire();
c.scrie();
cout << "-----------------------" << endl;
c.citire();
return 0;
}