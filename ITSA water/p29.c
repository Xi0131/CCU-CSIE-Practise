#include <stdio.h>

int main(){

    char c[11];
    scanf("%s", c);
    int a, b;
    a = (int) (c[0] / 10);
    b = (int) (c[0] % 10);
    int ans = (int) (a + (9 * b) + (8 * (c[1] - '0')) + (7 * (c[2] - '0')) + (6 * (c[3] - '0')) + (5 * (c[4] - '0')) + (4 * (c[5] - '0')) + (3 * (c[6] - '0')) + (2 * (c[7] - '0')) + c[8] + c[9]);
    if(ans % 10 == 0) printf("CORRECT!!!\n");
    else printf("WRONG!!!\n");

    return 0;
}