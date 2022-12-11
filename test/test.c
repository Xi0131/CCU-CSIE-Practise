#include<stdio.h>

void map_sys(int *money, int *aaa);

int main()
{
    int money = 100;
    int aaa[3];
    map_sys(&money, aaa);
    printf("%d", money);
    printf("%d", sizeof(aaa)/sizeof(aaa[0]));

    return 0;
}

void map_sys(int *money, int *aaa)
{
    *money -= 10;
    printf("%d", sizeof(aaa));
    return;
}