#include <stdio.h>

int main()
{
    int a = 0;
    int b = 1;
    int t = 0;
    int n = 10;
    for(int i = 0; i < n; ++i)
    {
        t += a+b;
        a = b;
        b = t;
    }
    printf("%d", t);
    return 0;
}
