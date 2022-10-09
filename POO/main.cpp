#include<iostream>
using namespace std;

int main()
{
    int a_size, a[a_size];
    string algoritm="---";
    cout << "Introdu marimea vectorului = ";
    cin >> a_size;

    for(int i=0; i<a_size; i++)
    {
        a[i] = rand();
    } 

    for(int i=0; i<a_size; i++)
    {
        cout << a[i] << ' '; 
    }
    int m;
    cin >> m;
}