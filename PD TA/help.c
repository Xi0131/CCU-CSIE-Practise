#include<stdio.h>

int main(){
    long long a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    long long t1 = c / b, t2 = a / d;
    // printf("%lld %lld\n", t1, t2);
    if(t1 <= t2) printf("Zara wins");
    else printf("Firelord wins");

    return 0;
}