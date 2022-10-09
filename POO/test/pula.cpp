#include <iostream>
#include <string>

class la_pula{
public:
    int a_size=0, *p;

    void select_pula(std::string algo, int *our_arr, int size){
        a_size=size;
        p=our_arr;

        if(algo=="mare"){
            std::cout << "Nu e mare";
        }
        else if(algo=="mititel"){
            std::cout << "Da e mititel";
        }
        else std::cout << "pasol nahui";
    }
};