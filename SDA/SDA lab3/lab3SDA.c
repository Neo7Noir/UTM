#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* replaceWord(const char* s, const char* oldW, const char* newW){
    char* result;
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);
  
    for (i = 0; s[i] != '\0'; i++){
        if (strstr(&s[i], oldW) == &s[i]){
            cnt++;
            i += oldWlen - 1;
        }
    }
  
    result = (char*)malloc(i + cnt * (newWlen - oldWlen) + 1);
  
    i = 0;
    while (*s){
        if (strstr(s, oldW) == s){
            strcpy(&result[i], newW);
            i += newWlen;
            s += oldWlen;
        }
        else
            result[i++] = *s++;
    }
  
    result[i] = '\0';
    return result;
}

char* replaceLastLineWord(const char* s, const char* oldW, const char* newW){
    char* result;
    int i = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);
    int c = 0;

    while(strstr(&s[i], oldW)){
	    i++;
	}
  
    result = (char*)malloc(strlen(s) - (strlen(oldW) - strlen(newW)));
  
    i--;

	while(*s){
		if(c == i){
			strcpy(&result[i], newW);
			i += newWlen; 
			s += oldWlen;
		}else 
			result[c++] = *s++;	
	}	
  
    result[i] = '\0';
    return result;
}

int main(){

    char word1[50], word2[50];
    int len1,len2;
    char rasp;

    printf("Dati primul cuvant parametric=> ");
    fflush(stdin);
    scanf("%s", &word1);
    printf("\nDati al doilea cuvant parametric=> ");
    fflush(stdin);
    scanf("%s", &word2);
    len1 = strlen(word1);
    len2 = strlen(word2);

    char *fisier = "finalF.txt";
    FILE *f;
    f = fopen(fisier, "w");

    char *fisier1 = "primulF.txt";
    FILE *g;
    char string[250];
    char* result = NULL;

    g = fopen(fisier1, "r");
    fgets(string, 250 ,g);
    printf("%s", string);
    fclose(g);

    result = replaceWord(string, word1, word2);

    fwrite(result, 1, strlen(result), f);

    char *fisier2 = "doiF.txt";
    FILE *h;
    result = NULL;

    h = fopen(fisier2, "r");
    fgets(string, 250 ,h);
    printf("%s", string);
    fclose(h);
    fwrite("\n", 1, strlen("\n"), f);

    result = replaceLastLineWord(string, word2, word1);

    fwrite(result, 1, strlen(result), f);

fclose(f);
}