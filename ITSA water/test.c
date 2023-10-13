#include <stdio.h>

#define watch_int(x) printf(#x " is me %d", x);

int main(){

    int asd = 123;
    watch_int(asd);

}