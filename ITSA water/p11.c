#include <stdio.h>

int main(){

    int r, c;
    scanf("%d %d", &r, &c);
    int arr[c][r];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &arr[j][i]);
        }
    }
    for(int i = 0; i < c; i++){
        for(int j = 0; j < r; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}