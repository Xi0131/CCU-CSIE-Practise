#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define debug printf("Debug line %d\n", __LINE__)
#define watch_int(x) printf(#x " is %d\n", x)
#define watch_string(x) printf(#x " is %s\n", x)

struct course
{
    char name[NAME_LENGTH];
    int course_id;
    struct course *next;
    struct course *prior;
    int prior_id;
};

struct course *search(int num, int tgt, struct course *list){
    for(int i = 0; (list->next != NULL) && (i < num); list = list->next, i++){
        if(list->course_id == tgt){
            return list;
        }
    }
    return NULL;
}

void insert(int num, int id, int next, int prior, char *name, struct course **list){
    struct course *buffer = (struct course*) malloc(sizeof(struct course));
    buffer->course_id = id;
    strcpy(buffer->name, name);
    buffer->next = NULL;
    buffer->prior = NULL;
    buffer->prior_id = prior;
    if(*list == NULL){
        *list = buffer;
    }
    else{
        struct course *temp = *list;
        for(; temp->next != NULL; temp = temp->next);
        temp->next = buffer;
        struct course *next_node = search(num, next, *list);
        if(next_node != NULL) buffer->next = next_node;
        else buffer->next = NULL;
        // struct course *prev = search(num, prior, *list);
        // buffer->prior = prev;
    }
}

void link_prior(int num, struct course **list){
    struct course *temp2 = *list;
    for(int i = 0; i < num; temp2 = temp2->next, i++){
        if(temp2->prior == NULL){
            struct course *prior_exist = search(num, temp2->prior_id, *list);
            if(prior_exist != NULL){
                temp2->prior = prior_exist;
            }
        }
    }
}

int main(){

    int num;
    struct course *list = NULL;
    scanf("%d", &num);

    for(int i = 0; i < num; i++){
        int id, next, prior;
        char *name = (char*) malloc(sizeof(char) * NAME_LENGTH);
        scanf("%d %d %d %s", &id, &next, &prior, name);
        insert(num, id, next, prior, name, &list);
    }

    link_prior(num, &list);

    struct course *buffer = list;
    while(1){
        printf("Current Course: %s\n", buffer->name);
        printf("[n] Next course. [p] Prior course [q] Quit: ");
        char cmd;
        scanf(" %c", &cmd);
        if(cmd == 'q') break;
        else if(cmd == 'n'){
            if(buffer->next == NULL) printf("There is no next course.\n");
            else buffer = buffer->next;
        }
        else if(cmd == 'p'){
            if(buffer->prior == NULL) printf("There is no previous course.\n");
            else buffer = buffer->prior;
        }
    }

    return 0;
}