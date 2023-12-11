#include <stdio.h>
typedef unsigned long long int ll;

int main(){

    ll p;
    scanf("%llu", &p);
    for(ll i = 0; i <= p; i++){
        if((p-i*i*i*i*i*i*i*i) % 7 == 0){
            ll b3 = (p-i*i*i*i*i*i*i*i) / 7;
            for(ll j = 0; j*j*j <= b3; j++){
                if(j*j*j == b3){
                    printf("%llu %llu", i, j);
                    return 0;
                }
            }
        }
    }

    return 0;
}