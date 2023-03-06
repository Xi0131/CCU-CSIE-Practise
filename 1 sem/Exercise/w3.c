#include<stdio.h>

int main()
{
    int i, j;
    char x, y, z;
    scanf("%d (!) %d R %c%c%c", &i, &j, &x, &y, &z);

    while(!((i%j)==0))
    {
        i++;
    }

    printf("%d\n%c%c%c", i, z, y, x);
    
    return 0;
}