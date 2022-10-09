#include <iostream>
#include <string>
#include "sort_algorithms.cpp"
int main() {

    int a[100], a_size, i;
    std::string algoritm="---";
    std::cout << "Introdu marimea vectorului = ";
    std::cin >> a_size;

    std::cout << "Introdu datele vectorului:\n";
    for(i=0; i<a_size; i++){
        std::cin >> a[i];
    }

    for(i=0; i<a_size; i++){
        std::cout << a[i] << " ";
    }
    std::cout << "\n";

    sort_algorithms obj;
    std::cout << "Algoritmul bubble sort --> Bubble"<< "\n";
    std::cout << "Algorimul insertion -----> Insertion"<< "\n";
    std::cout << "Algoritmul selection ----> Selection"<< "\n";
    std::cin >> algoritm;
    obj.alg_select(algoritm, a, a_size);
    return 0;
}
