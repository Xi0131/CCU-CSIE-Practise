#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);
    for(int i = 0, a, b, c; i < n; i++){
        scanf("%d %d %d", &a, &b, &c);
        if(a >= 60 && b >= 60 && c >= 60) printf("P\n");
        else if((a + b + c) >= 220) printf("P\n");
        else if((a + b + c) < 220 && (a < 60 || b >= 60 || c >= 60)) printf("M\n");
        else if((a + b + c) < 220 && (a >= 60 || b < 60 || c >= 60)) printf("M\n");
        else if((a + b + c) < 220 && (a >= 60 || b >= 60 || c < 60)) printf("M\n");
        else if(a >= 80 && b < 60 && c < 60) printf("M\n");
        else if(a < 80 && b < 60 && c < 60) printf("M\n");
        else if(a < 80 && b < 60 && c < 60) printf("M\n");
        else printf("F\n");
    }

    return 0;
}