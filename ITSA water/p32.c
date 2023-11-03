#include <stdio.h>
#include <ctype.h>

int main(){
    char str[101];
    fgets(str, 101, stdin);
    int n;
    scanf("%d", &n);
    n = n % 26;
    if(n == 0) printf("%s", str);
    else{
        for(int i = 0; str[i] != '\0'; i++){
            if(isalpha(str[i])){
                if(isupper(str[i])){
                    if((str[i] + n) > 'Z') putchar(str[i] - ('Z' - 'A' + 1) + n);
                    else putchar(str[i] + n);
                }
                else{
                    if((str[i] + n) > 'z'){
                        putchar(str[i] - ('z' - 'a' + 1) + n);
                    }
                    else putchar(str[i] + n);
                }                
            }
            else if(isdigit(str[i])){
                if((str[i] + n) > '9') putchar(str[i] - ('9' - '0' + 1) + n);
                else putchar(str[i] + n);
            }
            else putchar(str[i]);
        }
    }

    return 0;
}