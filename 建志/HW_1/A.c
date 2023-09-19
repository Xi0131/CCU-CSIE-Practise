#include<stdio.h>
#include<stdlib.h>

int sz, ball_x1, ball_y1, ball_x2, ball_y2, exit_a1, exit_b1, exit_a2, exit_b2;
int ori_map[501][501];
int map_1_visited[501][501];
int map_2_visited[501][501];

typedef struct double_linked_list{
    int x;
    int y;
    dll* next;
    dll* prev;
} dll;

typedef struct pair{
    int x;
    int y;
} pair;

typedef struct queue_list{
    int x;
    int y;
    int size;
    dll* next;
    dll* tail;
} dll;

void dll_push(dll* list, int x, int y){
    dll* tmp = (dll*) malloc(sizeof(dll));
    tmp->x = x;
    tmp->y = y;
    tmp->next = NULL;
    tmp->prev = NULL;
    if(list == NULL){
        list = tmp;
    }
    else{
        list->next = tmp;
        tmp->prev = list;
        list = tmp;
    }
}

void q_push(dll* queue, int new_x, int new_y){
    if(queue->size == 0){
        queue = init_queue(new_x, new_y);
    }
    else{
        dll* tmp = (dll*) malloc(sizeof(dll));
        tmp->x = new_x;
        tmp->y = new_y;
        tmp->next = NULL;
        tmp->tail = NULL;
        queue->tail = tmp;
        queue->size++;
        tmp->size = queue->size;
    }
}

void q_pop(dll* queue){
    dll* tmp = queue;
    if(tmp->next == NULL){
        dll* tmp = (dll*) malloc(sizeof(dll));
        tmp->x = -1;
        tmp->y = -1;
        tmp->next = NULL;
        tmp->tail = NULL;
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

dll* init_queue(int new_x, int new_y){
    dll* tmp = (dll*) malloc(sizeof(dll));
    tmp->x = new_x;
    tmp->y = new_y;
    tmp->next = NULL;
    tmp->tail = NULL;
    tmp->size = 1;
    return tmp;
}

dll* q1 = {-1, 0, NULL, NULL}, q2 = {-1, 0, NULL, NULL};

void bfs(int **map_visited, dll* q, int x, int y, int des_x, int des_y){
    pair parent[501][501];
    map_visited[x][y] = 1;
    q_push(q, x, y);
    while(q->size != 0){
        dll* tmp = q;
        q_pop(q);
        if(map_visited[x][y] == 1) continue;
        if(tmp->y + 1 != 1){
            q_push(q, tmp->x, tmp->y + 1); // up
            parent[tmp->x][tmp->y + 1] = (pair) {x, y};
        }
        if(tmp->x + 1 != 1){
            q_push(q, tmp->x + 1, tmp->y); // right
            parent[tmp->x + 1][tmp->y] = (pair) {x, y};
        }
        if(tmp->y - 1 != 1){
            q_push(q, tmp->x, tmp->y - 1); // down
            parent[tmp->x][tmp->y - 1] = (pair) {x, y};
        }
        if(tmp->x - 1 != 1){
            q_push(q, tmp->x - 1, tmp->y); // left
            parent[tmp->x - 1][tmp->y] = (pair) {x, y};
        }
        if(tmp->x == des_x && tmp->y == des_y){
            break;
        };
    }
}

pair stimulate(int* step, int pos_x, int pos_y){
    for(){
        
    }
    return (pair) {pos_x, pos_y};
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

    return 0;
}