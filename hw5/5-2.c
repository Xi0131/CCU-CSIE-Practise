#include<stdio.h>

void search(int fib[], int m, int initial);

int main()
{
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        int t = 1, size = 1, a = 0, b = 1;
        scanf("%d", &m);
        while(1)
        {
            t = a + b;
            a = b;
            b = t;
            if(t > m) break;
            ++size;
        }
        int fib[size][2];
        fib[0][0] = {0};
        for(int i = 0; i < size; ++i)
        {
            fib[i][1] = 
        }


    }

    return 0;
}

void search(int fib[], int m, int initial)
{
    if((m - fib[initial]) == 0)
    {

        return
    }
}