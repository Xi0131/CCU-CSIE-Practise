#include<stdio.h>

int main()
{
    int x, ans;
    scanf("%d", &x);
    if(x > 100 || x < 0)
    {
        ans = 0;
    }
    else if(x >= 90 && x <= 100)
    {
        ans = 1;
    }
    else if(x >= 75 && x <= 89)
    {
        ans = 2;
    }
    else if(x >= 60 && x <= 74)
    {
        ans = 3;
    }
    else
    {
        ans = 4;
    }

    switch(ans)
    {
    case 0:
        printf("error");
        break;
    case 1:
        printf("A");
        break;
    case 2:
        printf("B");
        break;
    case 3:
        printf("C");
        break;
    case 4:
        printf("D");
        break;
    }
    
    return 0;
}
