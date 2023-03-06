#include<stdio.h>

int main()
{
    int n[4][4];
    int rsum = 0, csum = 0, x;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            scanf("%d", &x);
            n[i][j] = x;
        }
    }
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%d\t", n[i][j]);
        }
        printf("\n");
    }
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            rsum += n[i][j];
        }
        printf("%d\t", rsum);
        rsum = 0;
    }
    printf("\n");

    for(int j = 0; j < 4; j++)
    {
        for(int i = 0; i < 4; i++)
        {
            csum += n[i][j];
        }
        printf("%d\t", csum);
        csum = 0;
    }
    printf("\n");

    int dsum1 = n[0][0] + n[1][1] + n[2][2] + n[3][3];
    int dsum2 = n[0][3] + n[1][2] + n[2][1] + n[3][0];
    printf("%d\t%d", dsum1, dsum2);
    
    return 0;
}
