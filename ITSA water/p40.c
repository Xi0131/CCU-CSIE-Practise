#include <stdio.h>

int main(){

    int num[10];
    for(int i = 0; i < 10; i++){
        char c;
        scanf("%c", &c);
        if(c == 'X') num[i] = 10;
        else num[i] = c - '0';
        getchar();
    }
    
    for(int i = 1; i < 10; i++){
        num[i] += num[i-1];
    }

    for(int i = 1; i < 10; i++){
        num[i] += num[i-1];
    }

    if(num[9] % 11 == 0) printf("YES\n");
    else printf("NO\n");

    return 0;
}