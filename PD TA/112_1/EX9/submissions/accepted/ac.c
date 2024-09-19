#include <stdio.h>

int dp[46] = {0, 1, 2};

int text(int n){
    if(n == 1) return 1;
    else if(n == 2) return 2;
    else if(dp[n] != 0) return dp[n];
    else{
        dp[n] = text(n-1) + text(n-2);
        return dp[n];
    } 
}

int main(){

    int n;
    scanf("%d", &n);
    printf("%d", text(n));

    return 0;
}