#include <stdio.h>
#include <stdlib.h>
#define debug printf("debug: %d\n", __LINE__)

typedef struct Node{
    int idx;
    int start;
    int end;
} node;

typedef struct Vector{
    node *data;
    int size;
} vector;

node *createNode(int idx, int head, int tail){
    node *tmp = (node*) malloc(sizeof(node));
    tmp->idx = idx;
    tmp->start = head;
    tmp->end = tail;
    return tmp;    
}

vector *createVec(){
    debug;
    vector *tmp = (vector*) malloc(sizeof(vector));
    debug;
    tmp->data = (node*) malloc(sizeof(node));
    tmp->size = 0;
    return tmp;
}

vector *pushback(vector *vec, int idx, int head, int tail){
    vec->size++;
    realloc(vec->data, vec->size * sizeof(node));
    vec->data[vec->size + 1].idx = idx;
    vec->data[vec->size + 1].start = head;
    vec->data[vec->size + 1].end = tail;
}

void expand_arr(int **arr, int *round_cnt, int n){
    (*round_cnt)++;
    realloc(arr, sizeof(arr[0]) * (*round_cnt));
    arr[(*round_cnt)] = (int*) malloc(sizeof(int) * n);
}

int main(){

    int n, round_cnt = 1;
    scanf("%d", &n);
    
    int **records = (int**) malloc(sizeof(int*));
    *records = (int*) malloc(sizeof(int) * n);
    
    int start_path[n], end_path[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &start_path[i]);
        records[0][i] = start_path[i];
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &end_path[i]);
    }
    int last_exist[n];

    // step 0
    expand_arr(records, &round_cnt, n);
    for(int i = 0; i < n; i++){
        if(start_path[i] == -1 && end_path[i] != -1){
            start_path[i] = end_path[i];
        }
        records[1][i] = start_path[i];
        printf("%d ", records[1][i]);
    }

    debug;
    vector *vec = createVec();
    // compress and store node into vector
    int tmp = 0, d = n - 1, unpush = 0;
    int head = 0;
    while(tmp != d){
        if((end_path[tmp] != -1) && (start_path[tmp] != -1)){
            pushback(vec, tmp, head, end_path[tmp]);
            unpush = 0;
            // node *newNode = createNode(tmp, head, end_path[tmp]);
            // push into vector
        }
        else{
            if(unpush == 0){
                head = tmp;
                unpush = 1;
            }
        }
        tmp = end_path[tmp];
    }

    for(int i = 0; i < vec->size; i++){
        printf("%d ", vec->data[i].idx);
    }

    int match = 0;
    while(!match){

    }

    return 0;
}