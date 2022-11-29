#include <stdio.h>

int main()
{
    int a, b, c, d, e, f;
    float g, h;

    scanf("%d + %d =", &a, &b);
    scanf("%d - %d =", &c, &d);
    scanf("%d * %d =", &e, &f);
    scanf("%f / %f =", &g, &h);

    printf("%d\n", a+b);
    printf("%d\n", c-d);
    printf("%d\n", e*f);
    printf("%.2f\n", g/h);

    return 0;
}