#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int ans = b - a;
    printf("1000: %d\n", ans / 1000);
    ans = ans - (ans / 1000) * 1000;
    printf("500: %d\n", ans / 500);
    ans = ans - (ans / 500) * 500;
    printf("100: %d\n", ans / 100);
    ans = ans - (ans / 100) * 100;
    printf("50: %d\n", ans / 50);
    ans = ans - (ans / 50) * 50;
    printf("10: %d\n", ans / 10);
    ans = ans - (ans / 10) * 10;
    printf("5: %d\n", ans / 5);
    ans = ans - (ans / 5) * 5;
    printf("1: %d\n", ans);
    printf("Total change: %d\n", b - a);
    return 0;
}