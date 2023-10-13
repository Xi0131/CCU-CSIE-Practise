#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);
    for(int i = 0, a, b, c, d; i < n; i++){
        char op;
        scanf(" %c %d %d %d %d", &op, &a, &b, &c, &d);
        if(op =='+'){
            printf("%d %d\n", a + c, b + d);
        }
        else if(op == '-'){
            printf("%d %d\n", a - c, b - d);
        }
        else{
            printf("%d %d\n", a * c - (b * d), a * d + b * c);
        }
    }

    return 0;
}