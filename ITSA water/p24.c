#include <stdio.h>

int main(){

    float r, p;
    int n;
    float ans = 0;
    scanf("%f %d %f", &r, &n, &p);
    for(int i = 0; i < n; i++){
        ans =  ans + p;
        ans *= (r + 1);
    }
    printf("%d\n", ans);

    return 0;
}