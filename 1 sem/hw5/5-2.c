#include<stdio.h>
#include<math.h>

int fib(int n, int a, int b);

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        printf("%d = ", x);
        fib(x, 0, 1);
        printf(" (fib)\n");
    }

    return 0;
}

int fib(int n, int a, int b)
{
    int t = a + b;
    if((n / t) < 1)
    {
        return n;
    }
    else if (n == t)
    {
        printf("1");
        //printf("%d ", t);
        return n-=t;
    }
    else if((n / t) > 1 || (n / t) == 1)
    {
        a = b;
        b = t;
        n = fib(n, a, b);
        if((n / t) < 1)
        {
            printf("0");//printf("%d ", t);
            return n;
        }
        else if((n / t) == 1)
        {
            printf("1");//printf("%d ", t);
            return n-=t;
        }
    }
}