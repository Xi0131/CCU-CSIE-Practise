#include <stdio.h>
#include <string.h>

char a[31], b[31], c[31], tmp[31];

int main(){

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s %s ", a, b);
        int lenA = strlen(a), lenB = strlen(b);
        int len = lenA > lenB ? lenA + 1 : lenB + 1;
        int carryOn;
        for(int x = lenA - 1, y = lenB - 1;; x--, y--){

            if((a[x] - '0' + b[y] - '0') > 9){
                if(carryOn){
                    c[len - 1] = (a[x] - '0' + b[y] - '0') % 10 + '0';
                    carryOn = 1;
                }
            }
            len--;

            if(x == 0){
                for(int k = y - 1; k >= 0; k--){
                    c[len - 1] = b[k] ;
                }
                break;
            }
            else{

                break;
            }
        }
    }

    return 0;
}