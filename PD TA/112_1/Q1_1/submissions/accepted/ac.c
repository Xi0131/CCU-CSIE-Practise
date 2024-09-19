#include <stdio.h>

int main(){

    char arr[4];
    scanf("%s", arr);
    for(int i = 3; i >= 0; i--) printf("%c", arr[i]);

    return 0;
}