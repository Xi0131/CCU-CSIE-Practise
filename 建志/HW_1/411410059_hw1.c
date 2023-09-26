#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// macro that helps to debug
#define debug printf("hi %d\n", __LINE__);

// variable and 2d array for size, coordinates of sources and destinations, and map
int sz, ball_x1, ball_y1, ball_x2, ball_y2, exit_a1, exit_b1, exit_a2, exit_b2;
int ori_map[501][501];

// pair to store coordinates
typedef struct{
    int x;
    int y;
} pair;

// queue for bfs and recording steps
typedef struct Queue{
    pair *pt;
    struct Queue *next;
    struct Queue *tail;
} queue;

// initiate pair structure and return it address
pair *make_pair(int x, int y){
    pair *tmp = (pair*) malloc(sizeof(pair));
    tmp->x = x;
    tmp->y = y;
    return tmp;
}

// push pair into queue
void push(queue **q, pair *p){
    queue *tmp = (queue*) malloc(sizeof(queue));
    tmp->pt = p;
    if((*q) != NULL){
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

// pop pair from queue
void pop(queue **q){
    queue *tmp = (*q);
    if(tmp != NULL){
        if(tmp->next == NULL){
            (*q) = NULL;
            free(tmp);
        }
        else{
            (*q)->next->tail = (*q)->tail;
            (*q) = (*q)->next;
            free(tmp);
        }
    }
}

// count elements in queue
int cnt_queue(queue *q){
    int cnt = 0;
    while(q != NULL){
        cnt++;
        q = q->next;
    }
    return cnt;
}

// bfs funtion that do bfs, trace parent node, extract direction of steps from parent and record steps
void bfs(int size, int x, int y, int *steps_recorded, int *steps_count, int *h1_filled, int *h2_filled){
    pair *parent[size][size];                   // 2d array for recording parent node
    int visited[size][size];                    // 2d array for recording visited node
    memset(visited, 0, size*size*sizeof(int));  // initiate "visited" with 0
    parent[x][y] = make_pair(0, 0);             // set parent of source with {0, 0} as breaking point

    queue *q = NULL;
    push(&q, &(pair){x, y});

    // body of bfs, break when contact with active destination, once contacted, deactivate destination with flag
    while(q != NULL){
        visited[q->pt->x][q->pt->y] = 1;
        if((q->pt->x == exit_a1 && q->pt->y == exit_b1) && !(*h1_filled)){
            pop(&q);
            (*h1_filled) = 1;
            break;
        }
        if((q->pt->x == exit_a2 && q->pt->y == exit_b2) && !(*h2_filled)){
            pop(&q);
            (*h2_filled) = 1;
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
    
    // set destination to trace
    int tx, ty;
    if((*h1_filled) == 1){
        (*h1_filled) = 2;
        tx = exit_a1, ty = exit_b1;
    }
    else tx = exit_a2, ty = exit_b2;
    
    // trace parents and push into queue
    queue *steps = NULL;
    while(parent[tx][ty]->x != 0){
        if(parent[tx][ty]->y < ty) push(&steps, make_pair(0, 0));
        if(parent[tx][ty]->x < tx) push(&steps, make_pair(1, 0));
        if(parent[tx][ty]->y > ty) push(&steps, make_pair(2, 0));
        if(parent[tx][ty]->x > tx) push(&steps, make_pair(3, 0));
        int next_x = tx, next_y = ty;
        tx = parent[next_x][next_y]->x;
        ty = parent[next_x][next_y]->y;
    }

    // extract and store steps into array
    int cnt = cnt_queue(steps);
    (*steps_count) += cnt;
    for(int i = 1; i <= cnt; i++){
        steps_recorded[(*steps_count) - i] = steps->pt->x;
        steps = steps->next;
    }
}

void stimulate(int *x, int *y, int *steps_recorded, int *steps_count){
    // ordinary stimulate
    for(int i = 0; i < (*steps_count); i++){
        if(steps_recorded[i] == 0 && ori_map[(*x)][(*y) + 1] != 1) (*y)++;
        if(steps_recorded[i] == 1 && ori_map[(*x) + 1][(*y)] != 1) (*x)++;
        if(steps_recorded[i] == 2 && ori_map[(*x)][(*y) - 1] != 1) (*y)--;
        if(steps_recorded[i] == 3 && ori_map[(*x) - 1][(*y)] != 1) (*x)--;
    }
}

int main(){

    // initiate array for record and variable for storing steps
    int steps_recorded1[250000], steps_count1 = 0;
    int steps_recorded2[250000], steps_count2 = 0;
    // flag for differentiate which hole is filled
    int hole_1_filled = 0, hole_2_filled = 0;

    // input
    scanf("%d", &sz);
    for(int j = sz - 1; j >= 0; j--){
        for(int i = 0; i < sz; i++){
            scanf("%d", &ori_map[i][j]);
        }
    }
    scanf("%d %d %d %d %d %d %d %d", &ball_x1, &ball_y1, &ball_x2, &ball_y2, &exit_a1, &exit_b1, &exit_a2, &exit_b2);
    // set variable for stimulate ball
    int tx1 = ball_x1, tx2 = ball_x2, ty1 = ball_y1, ty2 = ball_y2;

    bfs(sz, ball_x1, ball_y1, steps_recorded1, &steps_count1, &hole_1_filled, &hole_2_filled);
    stimulate(&tx2, &ty2, steps_recorded1, &steps_count1);
    bfs(sz, tx2, ty2, steps_recorded1, &steps_count1, &hole_1_filled, &hole_2_filled);

    // reset flag and do bfs with reversed order
    hole_1_filled = 0, hole_2_filled = 0;
    bfs(sz, ball_x2, ball_y2, steps_recorded2, &steps_count2, &hole_1_filled, &hole_2_filled);
    stimulate(&tx1, &ty1, steps_recorded2, &steps_count2);
    bfs(sz, tx1, ty1, steps_recorded2, &steps_count2, &hole_1_filled, &hole_2_filled);

    // output the step order with the smaller steps count
    if(steps_count1 < steps_count2)
    for(int i = 0 ; i < steps_count1; i++) printf("%d", steps_recorded1[i]);
    else
    for(int i = 0 ; i < steps_count2; i++) printf("%d", steps_recorded2[i]);

    return 0;
}