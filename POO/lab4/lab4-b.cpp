#include <iostream>
#include <string>

using namespace std;

class Hartie;
class Carte;
class Caiet;
class Caiet_notite;

class Hartie{
private:
    string material;
public:
    Hartie(string mat){
        material = mat;
    }
    
    void setMaterial(){
        cout << "Dati materialul" << endl;
        cin >> material;
    }
    void afisMaterial(){
        cout << "Materialul: " << material << endl;
    }
};

class Carte: public Hartie{
private:
    string denumirea;
    string autorul;
public:
    Carte(string mat, string denum, string aut):Hartie(mat){
    denumirea = denum;
    autorul = aut;
}

    void citire(){
        cout << "Denumirea: " << denumirea << endl;
        cout << "Autorul: " << autorul << endl;
        afisMaterial();
    }
};

class Caiet: public Hartie{   
private:
    string continut;
public:
    Caiet(string mat, string cont):Hartie(mat){
        continut = cont;
    }

    void scrie(){
        cout << "Introduceti continutul: " << endl;
        cin >> continut;
    }
    friend class caiet_de_notite;
};

class caiet_de_notite: public virtual Carte, public virtual Caiet{
public:
    caiet_de_notite(string mat, string denum, string aut, string cont):Carte(mat, denum, aut), Caiet(mat, cont){
        
    }

    void citire(){
        Carte::citire();
        cout << "Continutul: " << continut << endl;
    }
};

int main(){
caiet_de_notite c("bumbac", "Petrea", "Vasile Romanciuk", "continutul initial");
c.citire();
c.scrie();
cout << "-----------------------" << endl;
c.citire();
return 0;
}