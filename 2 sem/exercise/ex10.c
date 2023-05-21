#include <stdio.h>

unsigned int getRangeBits(unsigned int A, int i, int j){
    return A & 255;
}

unsigned int concatenate(unsigned int A, int i, int j, unsigned int B, int x, int y){
    unsigned int temp = B & 255;
    A = A >> 8;
    A = A << 8;
    return A | temp;
}

unsigned int E(unsigned int V){
    return V ^ 3610409;
}

int main(){

    unsigned int V = 520;
    unsigned int n, C, M, U;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &M);
        U = E(V);
        C = M ^ getRangeBits(U, 1, 8);
        V = concatenate(V, 9, 32, C, 1, 8);
        printf("%d ", C);
    }

    return 0;
}