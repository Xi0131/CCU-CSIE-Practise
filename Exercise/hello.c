#include <stdio.h>

int main()
{
    int n = 0;
    int ans = 0;
    int a = 0, b = 1;
    while(n < 100000000)
    {
        n = a + b;
        a = b;
        b = n;
        ++ans;
    }printf("%d", n);
    return 0;
}
