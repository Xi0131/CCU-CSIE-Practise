#include<stdio.h>

int main()
{   
    int arr[10];
    *arr = 1;
    printf("%d", *arr);
    int i, *p;
    p = &i;
    i = 0;
    printf("%d", *p);

    return 0;
}
