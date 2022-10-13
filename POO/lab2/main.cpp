#include<iostream>
#include "clasa.cpp"
using namespace std;

int main()
{
    int choise;
    paralelipiped a,b;
    a.citire();
    a.afisare(); cout << endl;
    b.init(7.5, 4, 3);
    b.afisare();
    cout << "\n\n";
    cout << "Paralelipiped cu suprafata maxima:\n";
    if (a.arie() > b.arie()) a.afisare();
    else b.afisare();

    cout << "\n\n";
    cout << "Paralelipiped cu perimetrul minim:\n";
    if (a.perimetru() > b.perimetru()) b.afisare();
    else a.afisare();

    
    return 0;
}