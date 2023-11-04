#include <stdio.h>

int main(){

    float arr[10];
    for(int i = 0; i < 10; i++){
        scanf("%f", &arr[i]);
    }
    float max = arr[0];
    float min = arr[0];

    for(int i = 1; i < 10; i++){
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }

    printf("maximum:%.2f\n", max);
    printf("minimum:%.2f\n", min);

    return 0;
}