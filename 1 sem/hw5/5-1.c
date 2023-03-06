#include<stdio.h>

int GCD(int j, int i)
{
    int t;
    while(i != 0)
    {
        t = i;
        i = j % i;
        j = t;
    }
    return j;
}

int main()
{
    int n, g = 0;
    do
    {
        scanf("%d", &n);
        if(n == 0) break;
        for(int i = 1; i < n; ++i)
        {
            for(int j = i + 1; j <= n; ++j)
            {
                g += GCD(j, i);
            }
        }
        printf("%d\n", g);
        g = 0;
    }while(n != 0);

    return 0;
}