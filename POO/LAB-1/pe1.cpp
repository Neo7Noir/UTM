#include<iostream>
#include <string>
using namespace std;

class cautare
{
public:
    int a_size = 0, *o;
    void metoda_select(string metoda, int *arr, int size)
    {
        a_size=size;
        o=arr;

        if(metoda =="max"){
            find_max();
        }
        else if(metoda == "min"){
            find_min();
        }
        else cout << "Da alt varic";
    }

    void find_max(){
        int max=o[0];
        for(int i=0; i<a_size; i++){
            if (max<o[i]){
                max = o[i];
            }
        } 
        cout << "Elementul maxim: " << max;
        }
    

    void find_min(){
        int min=o[0];
        for(int i=0; i<a_size; i++){
            if (min>o[i]){
                min = o[i];
            }
        }
        cout << "Elementul minim: " << min;
        
    }
};