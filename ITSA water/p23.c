#include <stdio.h>

int main(){

    int n, a, b, c, x, y, z;
    scanf("%d,%d,%d,%d", &n, &a, &b, &c);
    if(a * 15 + b * 20 + c * 30 > n) printf("0\n");
    else{
        n -= a * 15 + b * 20 + c * 30;
        z = n / 50;
        n %= 50;
        y = n / 5;
        n %= 5;
        x = n;
        printf("%d,%d,%d\n", x, y, z);
    }

    return 0;
}