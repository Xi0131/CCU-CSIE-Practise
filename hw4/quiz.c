#include<stdio.h>

int main()
{
    int total[5] = {0};
    int t;

    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            scanf("%d", &t);
            total[i] += t;
        }
    }

    for(int i = 0; i < 5; ++i) printf("%d %d %d\n", i+1, total[i], total[i]/5);
}