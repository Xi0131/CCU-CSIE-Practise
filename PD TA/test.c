#include<stdio.h>

int main(){
    long long a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    int t1 = c / b, t2 = d / a;
    if(t1 <= t2) printf("Zara wins");
    else printf("Firelord wins");

    return 0;
}