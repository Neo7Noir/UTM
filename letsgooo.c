#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main(){

char word1, word2;
int len1,len2;
char rasp;

printf("Dati primul cuvant parametric=> ");
scanf("%s", &word1);
printf("Dati al doilea cuvant parametric=> ");
scanf("%s", &word2);

len1 = strlen(word1);
len2 = strlen(word2);


char *fisier = "finalF.dat";
FILE *f;
f = fopen(fisier, "wt");

    char *fisier1 = "primulF.dat";
    FILE *g;
    char string;
    char *s = string;
    g = fopen(fisier1, "wt");
    if(g == NULL){
        printf("Fisierul este gol\n.");
        printf("Introduceti textul:\n");
        gets(string);
        fwrite(*s, 1, sizeof(string), g);
    }
    printf("Doriti sa rescrieti textul din fisier?(d/n)");
    scanf("%s", &rasp);
    if (rasp == 'd'){
        g = fopen(fisier1, "wt");
        printf("Introduceti textul:\n");
        gets(string);
        fwrite(*s, 1, sizeof(string), g);
    }

    
    























fclose(f);
}