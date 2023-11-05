#include <stdio.h>

int main(){

    double r, p;
    int n;
    double ans = 0;
    scanf("%lf %d %lf", &r, &n, &p);
    for(int i = 0; i < n; i++){
        ans =  ans + p;
        ans *= (r + 1);
    }
    printf("%.0f\n", ans);

    return 0;
}