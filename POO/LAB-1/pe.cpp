#include<iostream>
#include <string>
#include "pe1.cpp"

int main()
{
    std::string metoda="";
    int a_size;
    
    std::cout << "Da marimea: ";
    std::cin >> a_size;

    int a[a_size];

    for(int i=0; i<a_size; i++)
    {
        a[i] = rand();
    } 
    for(int i=0; i<a_size; i++)
    {
        cout << a[i] << ' '; 
    }
    std::cout << "\n";

    cautare obj;
    std::cout << "Metoda?!\n";
    std::cin >> metoda;
    obj.metoda_select(metoda, a, a_size);
    return 0;
}