#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);
    float a = 0, b = 0;
    if(n >= 701){
        a += 5.63 * (n - 700);
        b += 4.5 * (n - 700);
        n = 700;
    }
    if(n >= 501 && n <= 700){
        a += 4.97 * (n - 500);
        b += 4.01 * (n - 500);
        n = 500;
    }
    if(n >= 331 && n <= 500){
        a += 4.39 * (n - 330);
        b += 3.61 * (n - 330);
        n = 330;
    }
    if(n >= 121 && n <= 330){
        a += 3.02 * (n - 120);
        b += 2.68 * (n - 120);
        n = 120;
    }
    if(n > 0){
        a += 2.1 * n;
        b += 2.1 * n;
    }
    printf("Summer months:%.2f\n", a);
    printf("Non-Summer months:%.2f\n", b);

    return 0;
}