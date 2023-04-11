#include <stdio.h>
#include <stdlib.h>

#define NAME_LENGTH 50
#define debug printf("Hi\n")

struct course
{
    int course_id;
    struct course *next;
    struct course *prior;
    char course_name[NAME_LENGTH];
};

struct course *create_node(struct course *head){
    for(; head->course_id != NULL; head = head->next);
    head = (struct course*) malloc(sizeof(struct course));
    return head;
}

struct course *search_node(struct course *head, int tgt_id){
    for(; head->course_id != tgt_id; head = head->next);
    return head;
}

int main(){

    struct course *node = (struct course*) malloc(sizeof(struct course));
    struct course *head = node;
    int num;
    scanf("%d", &num);

    for(; num > 0; num--){
        int next, prior;
        node = create_node(head);
        printf("%d", head->course_id);
        scanf("%d %d %d %s", node->course_id, &next, &prior, node->course_name);
    }

    return 0;   
}