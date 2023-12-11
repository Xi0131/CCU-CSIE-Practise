#include <stdio.h>
typedef unsigned long long int ll;

ll fast(ll x, ll y){
    if(y == 1) return x;                                        // base
    else if(y % 2 == 0) return fast(x, y / 2) * fast(x, y / 2); // y is even
    else return fast(x, y - 1) * x;                             // y is odd
}

ll bis(ll L, ll R, ll remain){
    if(R >= L){
        ll mid = L + (R - L) / 2;
        ll midPow = fast(mid, 3);
        if(midPow == remain) return mid;
        else if(midPow > remain) return bis(L, mid - 1, remain);
        else if(midPow < remain) return bis(mid + 1, R, remain);
    }
    else return -1;
}

int main(){

    ll P;
    ll R = 0, B = 0;
    int flag = 0;
    scanf("%llu", &P);
    for(ll i = 1; i < P; i++){
        ll remain = (P - fast(i, 8)) / 7;
        if((P - fast(i, 8)) % 7 == 0){
            
            // brutal method
            // for(ll j = 0; j <= remain; j++){
            //     if(fast(j, 3) > remain) break;
            //     else if(fast(j, 3) == remain){
            //         R = i;
            //         B = j;
            //         flag = 1;
            //         break;
            //     }
            // }

            int tmp = bis(1, remain, remain);
            if(tmp != -1){
                R = i;
                B = tmp;
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    printf("%llu %llu\n", R, B);

    return 0;
}