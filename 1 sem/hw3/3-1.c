#include<stdio.h>

int main()
{
    int i, j, t;
    scanf("%d%d", &i, &j);
    if(i < j)
    {
        t = i;
        i = j;
        j = t;
    }

    while(j != 0)
    {
        t = j;
        j = i % j;
        i = t;
    }

    printf("%d", i);

    return 0;
}