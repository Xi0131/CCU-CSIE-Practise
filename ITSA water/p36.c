#include <stdio.h>

int main(){

    int n, flag = 0;
    scanf("%d", &n);
    if(n % 400 == 0) flag = 0;
    else if(n % 100 == 0) flag = 1;
    else if(n % 4 == 0) flag = 0;
    else flag = 1;
    if(flag) printf("Common Year\n");
    else printf("Bissextile Year\n");

    return 0;
}