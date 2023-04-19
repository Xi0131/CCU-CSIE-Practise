#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 1025
#define debug printf("Hi\n")

struct node{
    int word_cnt;
    char word[MAX_CHAR];
    struct node *next;
};

struct node *search(struct node *head, char *tgt){
    for(; head != NULL; head = head->next){
        if(strcmp(head->word, tgt) == 0){
            return head;
        }
        else{
            return NULL;
        }
    }
}

struct node *insert(struct node *head, char *buffer){
    for(; head != NULL; head = head->next);
    debug;
    strcpy(head->word, buffer);
    head->word_cnt = 0;
}

int main(){

    char *buffer = (char*) malloc(sizeof(char) * MAX_CHAR);
    struct node *head = (struct node*) malloc(sizeof(struct node));

    while (fgets(buffer, MAX_CHAR, stdin) != NULL){
        if(*buffer == '-'){
            for(int i = 0; buffer[i] != '\0'; buffer[i] = buffer[i+1], i++);
            struct node *temp = search(head, buffer);
            (temp->word_cnt)--;
            continue;
        }

        struct node *temp = search(head, buffer);
        if(temp == NULL){
            insert(head, buffer);
        }
        else{
            temp->word_cnt++;
        }
    }
    
    for(; head != NULL; head = head->next)
        printf("%s: %d\n", head->word, head->word_cnt);

    return 0;
}