#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define watch_int(x) printf(#x " is %d\n", x)
#define watch_string(x) printf(#x " is %s\n", x)
#define debug printf("Debug line %d\n", __LINE__)

struct student{
    char name[21];
    int score;
};

int main(){

    struct student *stu = (struct student*) calloc(sizeof(struct student), 40);
    int num;
    printf("Number of records you want to key in:");
    scanf("%d", &num);

    for(int i = 0; i < num; i++){
        printf("Enter name & score:");
        scanf("%s %d", stu[i].name, &stu[i].score);
    }

    int neet = 0;
    while (neet == 0)
    {
        neet = 1;
        for(int i = 0; i < num-1; i++){
            if(stu[i].score < stu[i+1].score){
                neet = 0;
                struct student temp;
                strcpy(temp.name, stu[i].name);
                temp.score = stu[i].score;
                strcpy(stu[i].name, stu[i+1].name);
                stu[i].score = stu[i+1].score;
                strcpy(stu[i+1].name, temp.name);
                stu[i+1].score = temp.score;
            }
        }
    }
    
    printf("name score\n");
    for(int i = 0; i < num; i++){
        printf("%s %d\n", stu[i].name, stu[i].score);
    }

    return 0;
}