#include<stdio.h>

int main()
{   
    int n;
    scanf("%d", &n);
    int arr1[n], arr2[n];
    for(int i = 0; i < n; ++i) scanf("%d", &arr1[i]);
    for(int i = 0; i < n; ++i) scanf("%d", &arr2[i]);
    printf("1st array: ");
    for(int i = 0; i < n; ++i) printf("%d ", arr2[i]);
    printf("\n2nd array: ");
    for(int i = 0; i < n; ++i) printf("%d ", arr1[i]);

    return 0;
}