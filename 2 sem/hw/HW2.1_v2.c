#include <stdio.h>
#include <stdlib.h>

#define NAME_LENGTH 50 

struct course
{
    int course_id;
    struct course *next;
    struct course *prior;
    char course_name[NAME_LENGTH];
};

void create_node(){

}

void search_node(){
    
}

int main(){

    struct course *node = (struct course*) malloc(sizeof(struct course));
    struct course *first = node;
    int num;
    scanf("%d", &num);

    for(; num > 0; num--){
        int next, prior;
        scanf("%d %d %d %s", node->course_id, &next, &prior, node->course_name);
    }

    return 0;
}