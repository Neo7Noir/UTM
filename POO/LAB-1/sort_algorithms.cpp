#include <iostream>
#include <string>

class sort_algorithms{
public:
    int a_size=0, *p;

    void alg_select(std::string algoritm, int *our_arr, int size){
        a_size=size;
        p=our_arr;

        if(algoritm=="Bubble"){
            bubble();
        }
        else if(algoritm=="Insertion"){
            insertion();
        }
        else if(algoritm=="Selection"){
            selection();
        }
        else{
            std::cout << "Introdu una din variantele programului.";
        }
    }

    void bubble(){
        for(int i=0; i<a_size; i++){
            for(int j=i+1; j<a_size; j++){
                if(p[j]<p[i]){
                    int temp=0;
                    temp = p[i];
                    p[i]=p[j];
                    p[j]=temp;
                }
            }
        }
        printArr();
    }

    void insertion(){
        for(int k=1; k<a_size; k++){
            int temp=p[k];
            int j=k-1;
            while(j>=0 && temp<=p[j])
            {
                p[j+1]=p[j];
                j=j-1;
            }
            p[j+1]=temp;
        }
        printArr();
    }
    void selection(){
        int pos, temp;
        for(int i=0; i<a_size; i++){
            pos = lowest_element(p,i);
            temp=p[i];
            p[i]=p[pos];
            p[pos]=temp;
        }
        printArr();
    }

private:
    int lowest_element(int myarr[], int i)
    {
        int low_element, pos, j;
        low_element=myarr[i];
        pos=i;
        for(j=i+1; j<a_size; j++){
            if(myarr[j]<low_element)
            {
                low_element=myarr[j];
                pos=j;
            }
        }
        return pos;
    }

    void printArr(){
        for(int i=0; i<a_size; i++){
            std::cout << p[i] << " ";
        }
        std::cout << "\n";
    }
};
