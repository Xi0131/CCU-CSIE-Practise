#include <stdio.h>
#include <stdlib.h>

#define NAME_LENGTH 50
#define debug printf("Debug line %d\n", __LINE__)
#define watch_int(x) printf(#x " is %d", x)
#define watch_string(x) printf(#x " is %s", x)

struct course
{
    int course_id;
    struct course *next;
    struct course *prior;
    char course_name[NAME_LENGTH];
};

struct course *create_node(struct course *head){
    for(; head->course_name != NULL; head = head->next){
        head = (struct course*) malloc(sizeof(struct course));
        break;
    }
    return head;
}

struct course *search_prior_node(struct course *head, int tgt_id){
    for(; head->course_id != tgt_id; head = head->next);
    return head;
}

int main(){

    struct course *head = (struct course*) malloc(sizeof(struct course));
    int num;
    scanf("%d", &num);

    for(; num > 0; num--){
        int next, t_prior;
        struct course *node = create_node(head);
        debug;
        scanf("%d %d %d %s", &(node->course_id), &next, &t_prior, node->course_name);
        printf("%d", head->course_id);
        node->prior = search_prior_node(head, t_prior);
        debug;
    }

    return 0;   
}