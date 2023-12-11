#include <stdio.h>
typedef unsigned long long int ll;

ll fast(ll x, ll y){
    if(y == 1) return x;                                        // base
    else if(y % 2 == 0) return fast(x, y / 2) * fast(x, y / 2); // y is even
    else return fast(x, y - 1) * x;                             // y is odd
}

int main(){

    ll x, y, m;
    scanf("%lld %lld %lld", &x, &y, &m);
    if(y == 0) printf("1\n");
    else printf("%llu\n", fast(x, y) % m);

    return 0;
}