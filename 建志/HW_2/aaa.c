#include <stdio.h>
#include <stdlib.h>
#define debug printf("debug: %d\n", __LINE__)

typedef struct Node{
    int idx;
    int head;
    int tail;
} node;

typedef struct Vector{
    node *data;
    int size;
} vector;

vector *createVec(){
    vector *tmp = (vector*) malloc(sizeof(vector));
    tmp->data = (node*) malloc(sizeof(node));
    tmp->size = 0;
    return tmp;
}

void pushback(vector *vec, int idx, int head, int tail){
    vec->size++;
    realloc(vec->data, vec->size * sizeof(node));
    vec->data[vec->size - 1].idx = idx;
    vec->data[vec->size - 1].head = head;
    vec->data[vec->size - 1].tail = tail;
}

void expand_arr(int ***arr, int *round_cnt, int n){
    (*round_cnt)++;
    
    int **new = (int **) malloc(sizeof(int *) * (*round_cnt));
    for (int i = 0; i < (*round_cnt) - 1; i++){
        new[i] = (*arr)[i];
    }
    free(*arr);
    (*arr) = new;
    
    // realloc(arr, sizeof(int*) * (*round_cnt));
    (*arr)[(*round_cnt) - 1] = (int*) malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        (*arr)[(*round_cnt) - 1][i] = (*arr)[(*round_cnt) - 2][i];
    }
}

void erase(vector *vec, int L, int R){
    for(int i = L, j = R; j < vec->size; i++, j++){
        vec->data[i].head = vec->data[j].head;
        vec->data[i].idx = vec->data[j].idx;
        vec->data[i].tail = vec->data[j].tail;
    }
    vec->size = vec->size - R;
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

    // part 1
    expand_arr(&records, &round_cnt, n);
    for(int i = 0; i < n; i++){
        if(start_path[i] == -1 && end_path[i] != -1){
            records[1][i] = end_path[i];
        }
    }

    vector *vec = createVec();
    // compress and store node into vector
    int tmp = 0, d = n - 1, unpush = 0;
    int head = 0, tail = 0;
    while(tmp != d){
        if(end_path[tmp] != -1) pushback(vec, tmp, 0, end_path[tmp]);
        tmp = start_path[tmp];
    }
    pushback(vec, tmp, 0, end_path[tmp]);
    tmp = 0;
    while(tmp != d){
        if((end_path[tmp] != -1) && (start_path[tmp] != -1)){
            for(int i = 0; i < vec->size; i++){
                if(vec->data[i].idx == tail){
                    vec->data[i].head = head;
                    tail = vec->data[i].tail;
                    break;
                }
            }
            unpush = 0;
            head = tmp;
        }
        else{
            if(unpush == 0){
                head = tmp;
                unpush = 1;
            }
            tail = end_path[tmp];
        }
        tmp = end_path[tmp];
    }
    vec->data[vec->size - 1].head = head;
    printf("size is %d\n", vec->size);
    for(int i = 0; i < vec->size; i++) printf("%d ", vec->data[i].head);
    printf("\n");
    for(int i = vec->size - 1; i >= 0; i--){
        if(vec->data[i - 1].tail == vec->data[i].idx){
            vec->data[i - 1].tail = vec->data[i].tail;
            erase(vec, i - 1, i);
        }
    }
    printf("%d\n", vec->size);

    // check vec
    // part 2
    while(vec->size >= 1){

        expand_arr(&records, &round_cnt, n);

        // find max jump and shorten the path
        int maxJump = 0, jump_Start_Pos = 0, jump_End_Pos = 0;
        for(int i = 0; i < vec->size; i++){
            int tmp = vec->data[i].tail;
            for(int j = 0; j < vec->size; j++){
                if(tmp == vec->data[j].head){
                    if(maxJump < (j - i)){
                        maxJump = (j - i);
                        jump_Start_Pos = i;
                        jump_End_Pos = j;
                    }
                    break;
                }
            }
        }
        records[round_cnt - 1][vec->data[jump_Start_Pos].idx] = vec->data[jump_End_Pos].head;
        vec->data[jump_End_Pos].head = vec->data[jump_Start_Pos].idx;
        // if(vec->size == 2) break;
        // printf("%d\n", maxJump);
        
        // prune
        expand_arr(&records, &round_cnt, n);

        for(int i = jump_Start_Pos + 1; i < jump_End_Pos; i++){
            records[round_cnt - 1][vec->data[i].idx] = vec->data[i].tail;
            for(int j = i + 1; j < vec->size; j++){
                if(vec->data[j].head == vec->data[i].tail) vec->data[j].head = vec->data[i].head;
            }
        }

        // printf("%d\n", jump_Start_Pos);

        erase(vec, jump_Start_Pos, jump_End_Pos);

        // break;
    }
    for(int i = 0; i < n; i++) records[round_cnt - 1][i] = end_path[i];

    printf("%d\n", round_cnt);
    for(int i = 0; i < round_cnt; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", records[i][j]);
        }
        printf("\n");
    }

    return 0;
}