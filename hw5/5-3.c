#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        int a, b, c = 1;
        scanf("%d %d", &a, &b);
        while((a * c) % b != 1 && c <= (b - 1)) ++c;
        if(c == b) printf("Inverse doesn't exist\n");
        else printf("multiplicative inverse is %d\n", c);
    }

    return 0;
}