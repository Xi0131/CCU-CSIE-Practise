#include <stdio.h>

int main(){

    int n;
    long long int ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        if(i % 3 == 0) ans += i;
    }
    printf("%lld\n", ans);

    return 0;
}