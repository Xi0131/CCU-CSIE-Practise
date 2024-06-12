#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define watch_int(x) printf(#x " is %d\n", x)
#define watch_string(x) printf(#x " is %s\n", x)
#define debug printf("Debug line %d\n", __LINE__)


typedef struct{
    char name[21];
    int score;
} student;


int cmp(const void * x, const void * y){
    student* a = (student*) x;
    student* b = (student*) y;
    if(a->score > b->score) return 0;
    if(a->score < b->score) return 1;
    if(a->score == b->score){
        if(strcmp(a->name, b->name) < 0) return 0;
        else return 1;
    }
}


int main(){


    student *stu = (student*) calloc(sizeof(student), 40);
    int num;
    scanf("%d", &num);


    for(int i = 0; i < num; i++){
        scanf("%s %d", stu[i].name, &stu[i].score);
    }


    qsort(stu, num, sizeof(student), cmp);
   
    for(int i = 0; i < num; i++){
        printf("%s %d\n", stu[i].name, stu[i].score);
    }


    return 0;
}
