#include<stdio.h>

long long int factorial(long long int N), fib(long long int i);
long long int mod_pow(long long int x, long long int y, long long int m);
long long int N;
long long int a;
long long int n, k;
long long int x, y, m;

int main()
{
    int queries, choice;
    printf("How many queries do you want: ");
    scanf("%d", &queries);
    
    for(int i = 0; i < queries; ++i)
    {
        printf("\nWhich type of query do you want: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nPlease enter N: ");
                scanf("%lld", &N);
                printf("\n%lld\n", factorial(N));
                break;
            case 2:
                printf("\nPlease enter i: ");
                scanf("%lld", &a);
                printf("\n%lld\n", fib(a));
                break;
            case 3:
                printf("\nPlease enter n and k: ");
                scanf("%lld %lld", &n, &k);
                printf("\n%lld\n", factorial(n) / (factorial(k) * factorial(n-k)));
                break;
            case 4:
                printf("\nPlease enter x, y and m: ");
                scanf("%lld%lld%lld", &x, &y, &m);
                printf("\n%lld\n", mod_pow(x, y, m));
                break;
        }
    }

    return 0;
}

long long int factorial(long long int N)
{
    if(N == 1) return 1;
    else return N * factorial(N-1);
}

long long int fib(long long int i)
{
    if(i == 0) return 0;
    else if(i == 1) return 1;
    else return fib(i-1) + fib(i-2);
}

long long int mod_pow(long long int x, long long int y, long long  int m)
{
    if(y == 1) return ((x%m) * (x%m)) % m;
    else if((y % 2) > 0) return ((x % m) * mod_pow(x, (y-1)/2, m)) % m;
    else return (mod_pow(x, y/2, m) * mod_pow(x, y/2, m)) % m;
}