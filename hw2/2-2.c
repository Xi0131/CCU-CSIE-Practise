#include<stdio.h>

int main()
{
    int x, y;
    scanf("%d:%d", &x, &y);
    if(x > 24 || x < 0 || y < 0 || y > 60)
    {
        printf("Incorrect Input");
    }
    else
    {
        if(x > 12)
        {
            x -= 12;
            printf("%d:%.2d PM", x, y);
        }
        else if(x == 0)
        {
            x += 12;
            printf("%d:%.2d AM", x, y);
        }
        else
        {
            printf("%d:%.2d AM", x, y);
        }
    }
    
    return 0;
}
