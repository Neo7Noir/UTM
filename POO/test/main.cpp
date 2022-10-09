#include <iostream>
#include <string>
#include "pula.cpp"

int main(){
    std::string algo="";
    int a_size=7;
    int a[a_size], i;

    std::cout <<"wat";

    for(i=0; i<a_size; i++){
        a[i]=rand();
    }
    for(i=0; i<a_size; i++){
        std::cout << a[i];
    }
    std::cout << "\n";

    la_pula obj;
    std::cout << "I SO\n";
    std::cin >> algo;
    obj.select_pula(algo, a, a_size);
    return 0;
}