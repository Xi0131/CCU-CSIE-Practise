#include<stdio.h>

void swap(int *arr1[], int *arr2[], int n);

int main()
{   
    int n;
    scanf("%d", &n);
    int arr1[n], arr2[n];
    for(int i = 0; i < n; ++i) scanf("%d", &arr1[i]);
    for(int i = 0; i < n; ++i) scanf("%d", &arr2[i]);
    swap(*arr1, *arr2, n);
    for(int i = 0; i < n; ++i) printf("%d ", arr1[i]);
    printf("\n");
    for(int i = 0; i < n; ++i) printf("%d ", arr2[i]);

    return 0;
}

void swap(int *arr1[], int *arr2[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        int t = *arr1[i];
        *arr1[i] = *arr2[i];
        *arr2[i] = t;
    }
}