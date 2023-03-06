#include <stdio.h>

int main()
{
    int m, d, y;
    scanf("%d/%d/%d", &m, &d, &y);
    printf("%.4d%.2d%.2d", y, m, d);

    return 0;
}
