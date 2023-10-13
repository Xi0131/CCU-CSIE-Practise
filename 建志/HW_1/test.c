#include<stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
} pair;

typedef struct Queue{
    int x, y;
    struct Queue *next;
    struct Queue *tail;
} queue;

void dequeue(queue *q, int *i, int *j){
    (*i) = q->x;
    (*j) = q->y;
    queue *tmp = q;
    q = q->next;
    free(tmp);
}

void bfs(int dest_x, int dest_y){

    queue *q;

    while(1){
        int x, y;
        dequeue(q, &x, &y);
        if(x == dest_x && y == dest_y){
            break;
        }
    }
}

int main(){
    
    queue *q = NULL;
    int x, y;
    dequeue(q, &x, &y);


    return 0;
}