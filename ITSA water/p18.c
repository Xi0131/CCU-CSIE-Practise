#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char qwer[] = "`1234567890-=~!@#$%^&*()_+qwertyuiop[]\\{}|asdfghjkl;':\"zxcvbnm,./<>? ";
    char  ans[] = "1234567890-==!@#$%^&*()_++wertyuiop[]\\\\}||sdfghjkl;''\"\"xcvbnm,.//>?? ";
    char  tmp[10000];
    fgets(tmp, 10000, stdin);
    tmp[strlen(tmp) - 1] = '\0';
    for(int i = 0; i < strlen(tmp); i++){
        if(isalpha(tmp[i]) && isupper(tmp[i])) tmp[i] = tolower(tmp[i]);
        for(int j = 0; j < strlen(qwer); j++){
            if(tmp[i] == qwer[j]){
                putchar(ans[j]);
            }
        }
    }
    printf("\n");

    return 0;
}