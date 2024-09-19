#include <stdio.h>


int main()
{
    int num;


    scanf("%d",&num);


    for(int i=2; i<=num; i++)
    {
        while(num>=i)
        {
            if(num%i==0)
            {
                printf("%d ",i);
                num=num/i;
            }
            else
            {
                break;
            }
        }
    }


    return 0;
}
