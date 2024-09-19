#include <stdio.h>

#define PI 3.14

int main(){
    
    int n, h, r;
    scanf("%d %d %d", &n, &h, &r);
    printf("%.3f %.3f\n", (PI * (float)h * r * r) / (n + 1), (h * r * r * PI) / (n + 1) * 2);

    return 0;
}