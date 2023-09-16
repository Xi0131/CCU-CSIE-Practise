#include<stdio.h>
#include<stdlib.h>

int sz, ball_x1, ball_y1, ball_x2, ball_y2, exit_a1, exit_b1, exit_a2, exit_b2;
int ori_map[501][501];
int map_1_visited[501][501];
int map_2_visited[501][501];

typedef struct linked_list{
    int direct;
    int size;
    struct linked_list* next;
    struct linked_list* tail;
} llist;

void push(llist* queue, int direction){
    if(queue->direct == -1){
        llist* tmp;
        queue = init_queue(direction);
        free(tmp);
    }
    else{
        llist* tmp = (llist*) malloc(sizeof(llist));
        tmp->direct = direction;
        tmp->next = NULL;
        tmp->tail = tmp;
        queue->tail = tmp;
        queue->size++;
        tmp->size = queue->size;
    }
}

void pop(llist* queue){
    llist* tmp = queue;
    if(tmp->next == NULL){
        llist* tmp = (llist*) malloc(sizeof(llist));
        tmp->direct = -1;
        tmp->next = NULL;
        tmp->tail = tmp;
        tmp->size = 0;
        queue = tmp;
    }
    else{
        queue = queue->next;
        queue->tail = tmp->tail;
        queue->size = tmp->size;
        free(tmp);
    }
}

llist* init_queue(int direction){
    llist* tmp = (llist*) malloc(sizeof(llist));
    tmp->direct = direction;
    tmp->next = NULL;
    tmp->tail = tmp;
    tmp->size = 1;
    return tmp;
}

void bfs(int **map){
    
}

int main(){

    scanf("%d %d %d %d %d %d %d %d %d", &sz, &ball_x1, &ball_y1, &ball_x2, &ball_y2, &exit_a1, &exit_b1, &exit_a2, &exit_b2);
    ball_y1 = sz - ball_y1 - 1;
    ball_y2 = sz - ball_y2 - 1;
    for(int i = 0; i < sz; i++){
        for(int j = 0; j < sz; j++){
            scanf("%d", &ori_map[i][j]);
        }
    }

    llist queue;
    llist* head, end;
    llist step1, step2;


    return 0;
}