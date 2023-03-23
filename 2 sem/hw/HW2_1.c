#include <stdio.h>
#include <stdlib.h>

struct course
{
    int id;
    struct course *next = (struct course*) malloc(sizeof(struct course));
    struct course *prior;
    char name[101];
};


int main(){
    printf("hi");
    int num;
    scanf("%d", &num);

    return 0;
}