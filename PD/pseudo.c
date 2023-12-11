#include <stdio.h>

unsigned long long int bis(unsigned long long int L, unsigned long long int R, unsigned long long int remain){
    /*recursive binary search*/
}

int main(){

    unsigned long long int P;
    unsigned long long int R = 0, B = 0;
    scanf("%llu", &P);
    for(/*search the range of R*/){
        if(/*(P - R^8) fulfill the characteristic*/){
            unsigned long long int remain = /*(P - R^8) / 7, which is B^3*/;
            unsigned long long int tmp = bis(1, remain, remain);
            if(/*tmp exist*/){
                R = /*R's value*/;
                B = tmp;
                printf("%llu %llu\n", R, B);
                return 0;
            }
        }
    }

    return 0;
}