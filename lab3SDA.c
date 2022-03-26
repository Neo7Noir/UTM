#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  

char* replaceWord(const char* s, const char* oldW,
                  const char* newW)
{
    char* result;
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);
  
    // Counting the number of times old word
    // occur in the string
    for (i = 0; s[i] != '\0'; i++) {
        if (strstr(&s[i], oldW) == &s[i]) {
            cnt++;
  
            // Jumping to index after the old word.
            i += oldWlen - 1;
        }
    }
  
    // Making new string of enough length
    result = (char*)malloc(i + cnt * (newWlen - oldWlen) + 1);
  
    i = 0;
    while (*s) {
        // compare the substring with the result
        if (strstr(s, oldW) == s) {
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
  
// Driver Program
int main()
{
    char str[] = "xxforxx xx for xx";
    char c[] = "xx";
    char d[] = "Geeks";
  
    char* result = NULL;
  

    char *fisier = "finalF.dat";
    FILE *f;
    f = fopen(fisier, "wt");
    
    
    
    fclose(f);
    // oldW string
    printf("Old string: %s\n", str);
  
    result = replaceWord(str, c, d);
    printf("New String: %s\n", result);
  
    free(result);
    return 0;
}
