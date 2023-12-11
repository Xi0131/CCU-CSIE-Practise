#include <stdio.h>
typedef unsigned long long int ll;

int main(){

    ll a = 1, b = 1;
    int n;
    scanf("%d", &n);
    ll arr[n + 1];
    if(n >= 1) arr[1] = 1;
    if(n >= 2) arr[2] = 2;
    for(int i = 3; i <= n; i++){
        ll tmp = a + b;
        arr[i] = tmp + arr[i - 1];
        b = a;
        a = tmp;
    }
    printf("%llu\n", arr[n]);

    return 0;
}