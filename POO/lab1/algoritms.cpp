#include<iostream>
#include <string>
using namespace std;

class sortare
{
public:
    void metoda_select(string metoda, int *arr, int size)
    {
        if(metoda=="Bubble"){
            bubbleSort(arr,size);
        }
        else if(metoda=="Cocktail"){
            CocktailSort(arr,size);
        }
        else if(metoda=="Insertion"){
            insertionSort(arr,size);
        }
        else printf("Nu este asa metoda");

    }

    void bubbleSort(int a[], int n)
    {
        int i, j;
        for (i = 0; i < n - 1; i++)
            for (j = 0; j < n - i - 1; j++)
                if (a[j] > a[j + 1])
                    swap(a[j], a[j + 1]);
        printArray(a,n);
    }


    void CocktailSort(int a[], int n)
    {
        bool swapped = true;
        int start = 0;
        int end = n - 1;
    
        while (swapped) {
            swapped = false;
    
            for (int i = start; i < end; ++i) {
                if (a[i] > a[i + 1]) {
                    swap(a[i], a[i + 1]);
                    swapped = true;
                }
            }
    
            if (!swapped)
                break;
            swapped = false; 
            --end;

            for (int i = end - 1; i >= start; --i) {
                if (a[i] > a[i + 1]) {
                    swap(a[i], a[i + 1]);
                    swapped = true;
                }
            }
            ++start;
        }
        printArray(a,n);
    }

    void insertionSort(int a[], int n) 
    { 
        int i, key, j; 
        for (i = 1; i < n; i++)
        { 
            key = a[i]; 
            j = i - 1; 
    
            while (j >= 0 && a[j] > key)
            { 
                a[j + 1] = a[j]; 
                j = j - 1; 
            } 
            a[j + 1] = key; 
        } 
        printArray(a,n);
    } 

    void printArray(int a[], int n)
    {
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
};