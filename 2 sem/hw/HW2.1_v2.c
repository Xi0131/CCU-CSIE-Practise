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
    struct course *list = (struct course*)malloc(sizeof(struct course));
    printf("hi");
    // struct course *head = (struct course*)malloc(sizeof(struct course));
    scanf("%d", &num);

    // head->next = (struct course*)malloc(sizeof(struct course));
    // head->prior = (struct course*)malloc(sizeof(struct course));
    // scanf("%d %d %d %s", &(head->course_id), &(head->next->course_id), &(head->prior->course_id), head->name);
    for(int i = 0; i < num; i++){
        list->next = (struct course*)malloc(sizeof(struct course));
        list->prior = (struct course*)malloc(sizeof(struct course));
        scanf("%d %d %d %s", &(list->course_id), &(list->next->course_id), &(list->prior->course_id), list->name);
        list = list->next;
    }
    for(int i = num-1; i >= 0; i--){
        list = list->prior;
    }
    
    while(1){
        char t;
        if(list->name == NULL && t == 'n') printf("There is no next course.\n");
        else if(list->name == NULL && t == 'p') printf("There is no previous course.\n");
        else printf("Current Course: %s\n", list->name);
        printf("[n] Next course. [p] Prior course [q] Quit: ");
        scanf(" %c", &t);
        if(t == 'q') break;
        else if(t == 'n') list = list->next;
        else if(t == 'p') list = list->prior;
    }

    return 0;
}