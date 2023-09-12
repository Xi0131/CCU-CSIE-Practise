#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define watch_int(x) printf(#x " is %d\n", x)
#define watch_string(x) printf(#x " is %s\n", x)
#define debug printf("Debug line %d\n", __LINE__)

int main(){

    int m, a = 0, b;
    char arr[101];
    scanf("%d", &m);
    getchar();
    scanf("%s", arr);
    scanf("%d", &b);
    int len = strlen(arr);
    int cnt = 0;
    while(cnt != len){
        a = a * 10 + arr[cnt] - '0';
        cnt++;
        if(a >= b){
            a %= b;
        }
    }
    a %= b;
    printf("%d", a);

    return 0;
}