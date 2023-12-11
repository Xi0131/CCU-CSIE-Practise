#include <stdio.h>
#include <string.h>

char a[129], b[513];

int main(){

    scanf("%s %s", a, b);
    int lenB = strlen(b), lenA = strlen(a), ans = 0;
    for(int i = 0; i <= lenB - lenA; i++){
        int flag = 0;
        for(int j = 0; j < lenA; j++){
            if(a[j] != b[i + j]) flag = 1;
        }
        if(!flag) ans++;
    }
    printf("%d\n", ans);

    return 0;
}