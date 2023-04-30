#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 1025
#define debug printf("Debug line %d\n", __LINE__)
#define watch_int(x) printf(#x " is %d\n", x)
#define watch_string(x) printf(#x " is %s\n", x)

struct node{
    int word_cnt;
    char word[MAX_CHAR];
    struct node *next;
};

void insert(char *input, struct node **list){
    struct node *buffer = (struct node*) malloc(sizeof(struct node));
    buffer->word_cnt = 1;
    strcpy(buffer->word, input);
    buffer->next = NULL;
    struct node *temp = *list;
    if(temp == NULL){
        *list = buffer;
    }
    else{
        for(; temp->next != NULL; temp = temp->next);
        temp->next = buffer;
    }
}

struct node* search(char *input, struct node* list){
    for(; list != NULL; list = list->next){
        if(strcmp(list->word, input) == 0){
            return list;
        }
    }
    return NULL;
}

int main(){

    char *input = (char*) malloc(sizeof(char) * MAX_CHAR);
    struct node *list = NULL;

    while(fgets(input, MAX_CHAR, stdin) != NULL){
        *(input + strlen(input) - 1) = '\0';
        if(*input == '-'){

            for(int i = 0; *(input + i) != '\0'; *(input + i) = *(input + i + 1), i++);
            struct node *tgt = search(input, list);
            tgt->word_cnt--;
        }
        else{
            struct node *temp = search(input, list);
            if(temp == NULL){
                insert(input, &list);
            }
            else temp->word_cnt++;
        }
    }

    for(; list != NULL; printf("%s: %d\n", list->word, list->word_cnt), list = list->next);
    
    return 0;
}