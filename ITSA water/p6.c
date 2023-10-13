#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);
    if(n >= 3 && n <= 5) printf("Spring\n");
    if(n >= 6 && n <= 8) printf("Summer\n");
    if(n >= 9 && n <= 11) printf("Autumn\n");
    if((n >= 1 && n <= 2) || n == 12) printf("Winter\n");

    return 0;
}