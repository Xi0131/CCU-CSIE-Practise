#include<stdio.h>
#include <stdlib.h>
#define debug printf("%d", __LINE__)

void expand_arr(int **arr, int *rounds, int n){
    (*rounds)++;
    realloc(arr, sizeof(arr[0]) * (*rounds));
    arr[(*rounds)] = (int*) malloc(sizeof(int) * n);
}

int main(){
    
    int n, rounds = 1;
    int **row = (int**) malloc(sizeof(int*) * rounds);
    expand_arr(row, &rounds, n);
    expand_arr(row, &rounds, n);
    expand_arr(row, &rounds, n);
    row[1] = (int*) malloc(sizeof(int));
    row[1][0] = 2;
    printf("%d", row[1][0]);

    return 0;
}