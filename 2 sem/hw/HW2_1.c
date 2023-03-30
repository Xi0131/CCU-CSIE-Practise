#include <stdio.h>
#include <stdlib.h>

#define NAME_LENGTH 50 

struct course
{
    char name[NAME_LENGTH];
    int course_id;
    struct course *next;
    struct course *prior;
};

int main(){

    int num;
    struct course *list = (struct course*) malloc(sizeof(struct course));
    struct course *head;
    scanf("%d", &num);

    head = list;
    head->prior = (struct course*) malloc(sizeof(struct course));
    for(int i = 0; i < num; i++){
        list->next = (struct course*) malloc(sizeof(struct course));
        scanf("%d %d %d %s", &(list->course_id), &(list->next->course_id), &(list->prior->course_id), list->name);
        list->next->prior = list;
        list = list->next;
    }
    head->prior = NULL;
    list->prior->next = NULL;
    
    while(1){
        char t;
        printf("Current Course: %s\n", head->name);
        printf("[n] Next course. [p] Prior course [q] Quit:");
        scanf(" %c", &t);
        if(head->next == NULL && t == 'n') printf("There is no next course.\n");
        else if(head->prior == NULL && t == 'p') printf("There is no previous course.\n");
        if(t == 'q') break;
        else if(head->next != NULL && t == 'n') head = head->next;
        else if(head->prior != NULL && t == 'p') head = head->prior;
        // printf("%s", head->next);
    }

    return 0;
}