#include<stdio.h>
#include<math.h>

int isFib_num(int n), fib(int n, int m);
int isPerfect_sqrt(long long n);

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        printf("%d = ", x);
        fib(x, x);
        printf(" (fib)\n");
    }

    return 0;
}

int isPerfect_sqrt(long long n)
{
    long long m = sqrt(n);
    return (m * m == n);//become logical operation, only return 0 or 1
}

int isFib_num(int n)
{
    //printf("%d ", n);
    return isPerfect_sqrt(5 * n * n + 4) || isPerfect_sqrt(5 * n * n - 4);//become logical operation, only return 0 or 1
}

int zero_fib(int n)
{
    if(n == 1)
    {
        printf("0");
        return 0;
    }
    //else if(n < 1) return 0;
    else if(isFib_num(n))
    {
        printf("0");
        return zero_fib(n-1);
    }
    else return zero_fib(n-1);
}

int fib(int n, int m)
{
    if(m == 0) return 0;
    else if(isFib_num(m) && (n == m))
    {
        printf("1");
        zero_fib(n-1);
        return 0;
    }
    else if(isFib_num(m))
    {
        if((n-m) >= 0)
        {
            n -= m;
            printf("1");
            return fib(n, m-1);
        }
        else
        {
            printf("0");
            return fib(n, m-1);
        }
    }
    else return fib(n, m-1);
}