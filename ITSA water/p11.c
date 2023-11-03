#include <stdio.h>

int main(){

    int r, c;
    while(scanf("%d", &r) != EOF){
        scanf("%d", &c);
        int arr[r][c];
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                scanf("%d", &arr[i][j]);
            }
        }
        for(int i = 0; i < c; i++){
            for(int j = 0; j < r; j++){
                printf("%d ", arr[j][i]);
            }
            if(i != (c - 1)) printf("\n");
        }
    }

    return 0;
}