#include <stdio.h>

unsigned short swap_bytes(unsigned short i){
    unsigned short temp;
    temp = i & 255;
    i = i >> 8;
    temp = temp << 8;
    temp += i;
    return temp;
}

int main(){

    int hexa, temp;
    scanf("%hx", &hexa);
    printf("%hx", swap_bytes(hexa));

    return 0;
}