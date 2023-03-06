#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int count = 1;
    for(int i = n; i > 0; i--)
    {
        for(int j = i-1; j > 0; j--)
        {
            printf(" ");
        }
        for(int j = 0; j < count; j++)
        {
            printf("*");
        }
        count += 2;
        printf("\n");
    }

    return 0;
}
