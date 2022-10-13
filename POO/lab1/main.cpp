#include<iostream>
#include <string>
#include "algoritms.cpp"
using namespace std;

int main()
{
    string metoda="";
    int a_size;
    
    cout << "Da marimea: ";
    cin >> a_size;
    
    int a[a_size];

    for(int i=0; i<a_size; i++)
    {
        a[i] = rand()%100;
    } 
    for(int i=0; i<a_size; i++)
    {
        cout << a[i] << ' '; 
    }
    cout << "\n";

    sortare obj;
    cout << "Pentru bubble sort: Bubble"<< "\n";
    cout << "Pentru CockTail sort: Cocktail"<< "\n";
    cout << "Pentru Insertion sort: Insertion"<< "\n";
    cin >> metoda;
    printf("Tabelul sortat:\n");
    obj.metoda_select(metoda, a, a_size);
    return 0;
}