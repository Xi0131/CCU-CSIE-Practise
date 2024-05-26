#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int src, dst;
} pair;

typedef struct node {
    int v1, v2;
    struct node *left;
    struct node *right;
} TreeNode;

typedef struct {
    int size;
    TreeNode *front;
} vector;

typedef struct {
    int *array;
    int front, rear;
    int capacity;
} adjacent_list;

typedef struct {
    int* data;
    int size;
    int capacity;
} DynamicVector;

void push_back(DynamicVector *vec, int x) {
    if(vec->size == 0) {
        vec->size++;
        vec->data = (int*) malloc(sizeof(int));
        vec->data[0] = x;
    }
    else {
        vec->size++;
        printf("size %d\n", vec->size);
        vec->data = realloc(vec->data, vec->size * sizeof(int));
        vec->data[vec->size-1] = x;
    }
}

int main(){

    int nodes_num, links_num, timeslots, reqs_num;
    scanf("%d %d %d %d", &nodes_num, &links_num, &timeslots, &reqs_num);
    int nodeID[nodes_num];
    pair req[reqs_num];
    for(int i = 0; i < nodes_num; i++) scanf("%d %d", &i, &nodeID[i]);

    // for(int i = 0; i < links_num; i++) scanf("%d %d %d", i, link[i].end1, link[i].end2);
    DynamicVector adj_list[nodes_num];
    for(int i = 0; i < nodes_num; i++) adj_list[i].size = 0;
    for(int i = 0, a, b; i < links_num; i++){
        scanf("%d %d %d", &i, &a, &b);
        push_back(&adj_list[a], b);
        push_back(&adj_list[b], a);
    }
    for(int i = 0; i < nodes_num; i++){
        for(int j = 0; j < adj_list[i].size; j++){
            printf("%d\n", adj_list[i].data[j]);
        }
        printf("hi\n");
    }

    for(int i = 0; i < reqs_num; i++) scanf("%d %d %d", &i, &req[i].dst, &req[i].src);

    return 0;
}