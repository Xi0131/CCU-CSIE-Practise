#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    char *words[100];
    int method, n, str_len = 100;
    scanf("%d %d", &method, &n);
    for(int i = 0; i < n; i++){
        words[i] = (char*) malloc(sizeof(char) * 100);
        scanf("%s", words[i]);
        str_len = strlen(words[i]) < str_len ? strlen(words[i]) : str_len;
    }

    // for(int i = 0; i < n; i++){
    //     printf("%s", words[i]);
    // }

    return 0;
}