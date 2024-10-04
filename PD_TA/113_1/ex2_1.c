#include <stdio.h>

int main(){
    int t1, t2, t3, t4;
    scanf("%d : %d", &t1, &t2);
    scanf("%d : %d", &t3, &t4);
    printf("%d", t3 * 60 + t4 - t1 * 60 - t2);
    return 0;
}