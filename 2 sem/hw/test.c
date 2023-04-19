#include <stdio.h>
#include <string.h>

struct person{
    char first[10];
    char middle;
    char last[10];
};

typedef struct{
    struct person name;
    int id, age;
    char sex;
} student;

int main(){

    student st1 = (__1__);

    student *st_ptr = &st1;

    printf("First: %s\n", (__2__));
    printf("Age: %d\n", (__3__));

    return 0;
}