#include <stdio.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble(int *arr, int size){
    for(int i = 0; i < size - 1; i++)
        for(int j = 0; j < size - i - 1; j++)
            if(arr[j] > arr[j + 1]){
                swap(arr + j, arr + (j + 1));
                printf("%d %d\n", arr[j], arr[j+1]);
            }
}

void selection(int *arr, int size){
    for(int i = 0; i < size; i++){
        int *buffer = &arr[i];
        for(int j = i; j < size; j++){
            if(arr[j] < *buffer){
                buffer = &arr[j];
            }
        }
        if(arr[i] != *buffer){
            swap(&arr[i], buffer);
            printf("%d %d\n", arr[i], *buffer);
        }
    }
}

void insertion(int *arr, int size){
    for(int i = 1; i < size; i++){
        int pos = i;
        for(; pos > 0; pos--){
            if(arr[pos] >= arr[pos - 1]) break;
            else swap(&arr[pos], &arr[pos - 1]);
        }
        // if(arr[i] < arr[i - 1]){
        //     for(int j = i - 1; j >= 0; j--){
        //         printf("%d! ", j);
        //         if(arr[i] < arr[j]){
        //             swap(&arr[i], &arr[j]);
        //             printf("%d %d\n", arr[i], arr[j]);
        //             pos = j;
        //         }
        //     }
        // }
        printf("%d\n", pos);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    char type;
    scanf(" %c", &type);
    
    if(type == 'B'){
        bubble(arr, n);
    }
    else if(type == 'S'){
        selection(arr, n);
    }
    else{
        insertion(arr, n);
    }

    return 0;
}