#include<stdio.h>

int main()
{
    int item, month, date, year;
    float price;
    scanf("%d %f %d/%d/%d", &item, &price, &month, &date, &year);
    printf("Item\tUnit\tPurchase\n\tPrice\tDate\n");
    printf("%d\t$%.2f\t%.2d\\%.2d\\%.4d", item, price, month, date, year);
    
    return 0;
}
