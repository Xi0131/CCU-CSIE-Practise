#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define debug printf("Debug line %d\n", __LINE__)
#define watch_int(x) printf(#x " is %d", x)
#define watch_string(x) printf(#x " is %s", x)

struct course
{
    char name[NAME_LENGTH];
    int course_id;
    struct course *next;
    struct course *prior;
};

struct course *search(int tgt, struct course *list){
    for(; list != NULL; list++){
        if(list->course_id == tgt){
            return list;
        }
    }
    return NULL;
}

void insert(int id, int next, int prior, char *name, struct course **list){
    struct course *buffer = (struct course*) malloc(sizeof(struct course));
    buffer->course_id = id;
    strcpy(buffer->name, name);
    if(prior == -1) buffer->prior = NULL;
    if(*list == NULL){
        *list = buffer;
    }
    else{
        struct course *temp = *list;
        for(; temp->next != NULL; temp++);
        temp->next = buffer;
        struct course *prev = search(prior, *list);
        buffer->prior = prev;
    }
}


int main(){

    int num;
    struct course *list = NULL;
    scanf("%d", &num);

    for(int i = 0; i < num; i++){
        int id, next, prior;
        char *name;
        scanf("%d %d %d %s", &id, &next, &prior, name);
        insert(id, next, prior, name, &list);
    }

    while(1){
        struct course *buffer = list;
        debug;
        printf("Current Course: %s\n", buffer->name);
        printf("[n] Next course. [p] Prior course [q] Quit:");
        char cmd;
        debug;
        scanf("%c", &cmd);
        debug;
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