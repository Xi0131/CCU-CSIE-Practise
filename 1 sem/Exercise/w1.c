#include <stdio.h>
//using namespace std;

int main()
{
    int x;
    scanf("%d", &x);

    int a, b, c, d, e;
    a = x/100;
    x = x - a*100;
    b = x/50;
    x = x - b*50;
    c = x/10;
    x = x - c*10;
    d = x/5;
    x = x - d*5;
    e = x;

    printf("100g bags: %d\n", a);
    printf("50g bags: %d\n", b);
    printf("10g bags: %d\n", c);
    printf("5g bags: %d\n", d);
    printf("1g bags: %d\n", e);

    return 0;
}
