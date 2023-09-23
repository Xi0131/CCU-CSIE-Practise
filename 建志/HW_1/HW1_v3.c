#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define debug printf("hi %d\n", __LINE__);

int sz, ball_x1, ball_y1, ball_x2, ball_y2, exit_a1, exit_b1, exit_a2, exit_b2;
int ori_map[501][501];

typedef struct{
    int x;
    int y;
} pair;

typedef struct Queue{
    pair *pt;
    struct Queue *next;
    struct Queue *tail;
} queue;

pair *make_pair(int x, int y){
    pair *tmp = (pair*) malloc(sizeof(pair));
    tmp->x = x;
    tmp->y = y;
    return tmp;
}

void push(queue **q, pair *p){
    queue *tmp = (queue*) malloc(sizeof(queue));
    tmp->pt = p;
    if(*q != NULL){
        tmp->next = NULL;
        (*q)->tail->next = tmp;
        (*q)->tail = tmp;
    }
    else{
        tmp->tail = tmp;
        tmp->next = NULL;
        (*q) = tmp;
    }
}

void pop(queue **q){
    queue *tmp = (*q);
    if(tmp != NULL){
        if(tmp->next == NULL){
            q = NULL;
            free(tmp);
        }
        else{
            (*q)->next->tail = (*q)->tail;
            (*q) = (*q)->next;
            free(tmp);
        }
    }
}

int cnt_queue(queue *q){
    int cnt = 0;
    while(q != NULL){
        cnt++;
        q = q->next;
    }
    return cnt;
}

void bfs(int size, int x, int y, int *steps_recorded, int *steps_count, int flag){
    pair *parent[size][size];
    int visited[size][size];
    memset(visited, 0, size*size*sizeof(int));
    parent[x][y] = make_pair(0, 0);

    queue *q = NULL;
    push(&q, &(pair){x, y});

    while(q != NULL){
        visited[q->pt->x][q->pt->y] = 1;
        if((q->pt->x == exit_a1 && q->pt->y == exit_b1) && flag){
            pop(&q);
            break;
        }
        if((q->pt->x == exit_a2 && q->pt->y == exit_b2) && !flag){
            pop(&q);
            break;
        }
        if(ori_map[q->pt->x][q->pt->y + 1] != 1 && visited[q->pt->x][q->pt->y + 1] != 1){
            push(&q, make_pair(q->pt->x, q->pt->y + 1)); // up
            parent[q->pt->x][q->pt->y + 1] = make_pair(q->pt->x, q->pt->y);
        }
        if(ori_map[q->pt->x + 1][q->pt->y] != 1 && visited[q->pt->x + 1][q->pt->y] != 1){
            push(&q, make_pair(q->pt->x + 1, q->pt->y)); // right
            parent[q->pt->x + 1][q->pt->y] = make_pair(q->pt->x, q->pt->y);
        }
        if(ori_map[q->pt->x][q->pt->y - 1] != 1 && visited[q->pt->x][q->pt->y - 1] != 1){
            push(&q, make_pair(q->pt->x, q->pt->y - 1)); // down
            parent[q->pt->x][q->pt->y - 1] = make_pair(q->pt->x, q->pt->y);
        }
        if(ori_map[q->pt->x - 1][q->pt->y] != 1 && visited[q->pt->x - 1][q->pt->y] != 1){
            push(&q, make_pair(q->pt->x - 1, q->pt->y)); // left
            parent[q->pt->x - 1][q->pt->y] = make_pair(q->pt->x, q->pt->y);
        }
        pop(&q);
    }
    
    int tx, ty;
    if(flag == 1){
        tx = exit_a1, ty = exit_b1;
    }
    else tx = exit_a2, ty = exit_b2;
    
    queue *steps = NULL;
    while(parent[tx][ty]->x != 0){
        if(parent[tx][ty]->y < ty) push(&steps, &(pair){0, 0});
        if(parent[tx][ty]->x < tx) push(&steps, &(pair){1, 0});
        if(parent[tx][ty]->y > ty) push(&steps, &(pair){2, 0});
        if(parent[tx][ty]->x > tx) push(&steps, &(pair){3, 0});
        int next_x = tx, next_y = ty;
        tx = parent[next_x][next_y]->x;
        ty = parent[next_x][next_y]->y;
    }

    int cnt = cnt_queue(steps);
    (*steps_count) += cnt;
    for(int i = 1; i <= cnt; i++){
        steps_recorded[(*steps_count) - i] = steps->pt->x;
        steps = steps->next;
    }
}

void stimulate(int *x, int *y, int *steps_recorded, int *steps_count){
    for(int i = 0; i < (*steps_count); i++){
        if(steps_recorded[i] == 0 && ori_map[(*x)][(*y) + 1] != 1) (*y)++;
        if(steps_recorded[i] == 1 && ori_map[(*x) + 1][(*y)] != 1) (*x)++;
        if(steps_recorded[i] == 2 && ori_map[(*x)][(*y) - 1] != 1) (*y)--;
        if(steps_recorded[i] == 3 && ori_map[(*x) - 1][(*y)] != 1) (*x)--;
    }
}

int main(){

    int steps_recorded1[2501], steps_count1 = 0;
    int steps_recorded2[2501], steps_count2 = 0;

    scanf("%d", &sz);
    for(int j = sz - 1; j >= 0; j--){
        for(int i = 0; i < sz; i++){
            scanf("%d", &ori_map[i][j]);
        }
    }
    scanf("%d %d %d %d %d %d %d %d", &ball_x1, &ball_y1, &ball_x2, &ball_y2, &exit_a1, &exit_b1, &exit_a2, &exit_b2);
    int tx1 = ball_x1, tx2 = ball_x2, ty1 = ball_y1, ty2 = ball_y2;

    bfs(sz, ball_x1, ball_y1, steps_recorded1, &steps_count1, 1);
    stimulate(&tx2, &ty2, steps_recorded1, &steps_count1);
    bfs(sz, tx2, ty2, steps_recorded1, &steps_count1, 0);

    bfs(sz, ball_x2, ball_y2, steps_recorded2, &steps_count2, 1);
    stimulate(&tx1, &ty1, steps_recorded2, &steps_count2);
    bfs(sz, tx1, ty1, steps_recorded2, &steps_count2, 0);

    // if(steps_count1 < steps_count2)
    for(int i = 0 ; i < steps_count1; i++) printf("%d", steps_recorded1[i]);
    // else
    printf("\n");
    for(int i = 0 ; i < steps_count2; i++) printf("%d", steps_recorded2[i]);

    return 0;
}