#include <stdio.h>

int main(){

    int space;
    int size = 0;
    long long int sum = 0;
    do{
        int tmp;
        scanf("%d", &tmp);
        size++;
        sum += tmp;
        space = getchar();
        if(space == '\n'){
            printf("Size: %d\n", size);
            printf("Average: %.3f\n", (float) sum / (float) size);
            size = 0;
            sum = 0;
        }
    }while(space != EOF);

    return 0;
}