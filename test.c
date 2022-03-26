#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	char string[] = "Andrei Andrei Andrei";
	char *s = string;
	char word[] = "lox";
	int len = 6, len2 = 3, i = 0, c = 0;
	
	while(strstr(&string[i], "Andrei")){
		i++;
	}
	printf("%d ", strlen(string) - (strlen("Andrei") - strlen(word)));

	char *result = (char*)malloc(strlen(string) - (strlen("Andrei") - strlen(word)));

	i--;
	while(*s){
		if(c == i){
			strcpy(&result[i], word);
			i += len2; 
			s += len;
		}else 
			result[c++] = *s++;	
	}		

	printf("%s", result);

	return 0;
}
