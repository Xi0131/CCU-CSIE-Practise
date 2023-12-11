#include <stdio.h>
#include <string.h>

int main(){

    char arr[10001];
    scanf("%s", arr);
    int len = strlen(arr);
    int n = len / 2;
    for(int i = 0; i < n; i++){
        if(arr[i] != arr[len - 1 - i]){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");

    return 0;
}