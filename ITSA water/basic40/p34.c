#include <stdio.h>

int main(){

    int n, m;
    while(scanf("%d", &n) != EOF){
        scanf("%d", &m);
        if(m == 1) printf("%.1f\n", (float) (n - 80) * 0.7);
        else printf("%.1f\n", (float) (n - 70) * 0.6);
    }

    return 0;
}