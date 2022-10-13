#include<iostream>
using namespace std;

class paralelipiped{
double lung,lat,inalt;
public:
    void citire(){
        cout << "Dati masurile paralelipipedului:\n";

        cout << "Lungimea: ";
        cin >> lung; cout << "\n";
        
        cout << "Latimea: ";
        cin >> lat; cout << "\n";
        
        cout << "Inaltimea: ";
        cin >> inalt; cout << "\n";
    };
    void afisare(){
        cout << "Lungimea = "<< lung << "cm" <<endl;
        cout << "Latimea = "<< lat << "cm" << endl;
        cout << "Inaltimea = "<< inalt << "cm" << endl;
        cout << "Perimetrul = "<< perimetru() << "cm" <<endl;
        cout << "Aria = "<< arie() << "cm^2" <<endl;
    };
    double arie(){
        return lung*inalt;
    };
    double perimetru(){
        return 2*lung*lat;
    };
    void init(double a, double b, double c){
        lung=a;
        lat=b;
        inalt=c;
    };
};
