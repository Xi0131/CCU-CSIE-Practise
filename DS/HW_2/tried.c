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
    node *new = (node*) malloc((vec->size + 1) * sizeof(node));
    if(vec->size != 0)
    for(int i = 0; i < vec->size; i++){
        new[i].idx = vec->data[i].idx;
        new[i].head = vec->data[i].head;
        new[i].tail = vec->data[i].tail;
    }
    vec->size++;
    new[vec->size - 1].idx = idx;
    new[vec->size - 1].head = head;
    new[vec->size - 1].tail = tail;
    free(vec->data);
    vec->data = new;
}

void expand_arr(int ***arr, int *round_cnt, int n){
    (*round_cnt)++;
    
    int **new = (int **) malloc(sizeof(int *) * (*round_cnt));
    for (int i = 0; i < (*round_cnt) - 1; i++){
        new[i] = (*arr)[i];
    }
    free(*arr);
    (*arr) = new;
    
    (*arr)[(*round_cnt) - 1] = (int*) malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        (*arr)[(*round_cnt) - 1][i] = (*arr)[(*round_cnt) - 2][i];
    }
}

void erase(vector *vec, int L, int R){
    // printf("%d %d\n", L, R);
    for(int i = L, j = R; j < vec->size; i++, j++){
        vec->data[i].head = vec->data[j].head;
        vec->data[i].idx = vec->data[j].idx;
        vec->data[i].tail = vec->data[j].tail;
    }
    vec->size = vec->size - R + L;
}

int judge(int **arr, int round_cnt, int n){
    for(int i = 0; i < n; i ++){
        if(arr[0][i] != arr[round_cnt][i]) return 0;
    }
    return 1;
}

int main(){

    int n, round_cnt = 1;
    int inversed_path[100001] = {0};
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
        if(end_path[i] != -1) inversed_path[end_path[i]] = i;
    }
    inversed_path[0] = -1;

    // connect those who not connected
    expand_arr(&records, &round_cnt, n);
    for(int i = 0; i < n; i++){
        if(start_path[i] == -1 && end_path[i] != -1){
            records[1][i] = end_path[i];
        }
    }
    
    // compress and store node into vector
    vector *vec = createVec();
    int tmp = 0, d = n - 1, on_hold = 0;
    while(1){
        if(end_path[tmp] != -1 || tmp == d){
            if(!on_hold){
                pushback(vec, tmp, 0, end_path[tmp]);
            }
            if(tmp == 0){
                vec->data[vec->size - 1].head = -1;
                if(start_path[tmp] == end_path[tmp]){
                    on_hold = 1;
                }
            }
            else if(start_path[inversed_path[tmp]] != -1){
                if(start_path[tmp] == end_path[tmp] && tmp != d){
                    on_hold = 1;
                }
                else{
                    vec->data[vec->size - 1].head = tmp;
                    on_hold = 0;
                }
            }
            else{
                int back_track = tmp;
                while(start_path[inversed_path[back_track]] == -1){
                    back_track = inversed_path[back_track];
                }
                vec->data[vec->size - 1].head = back_track;
            }
            if(tmp == d) break;
        }
        tmp = start_path[tmp];
    }
    
    // two steps mathod
    while(vec->size != 1){
        printf("before\n");
        for(int i = 0; i < vec->size; i++){
            printf("%d ", vec->data[i].idx);
        } printf("\n");
        expand_arr(&records, &round_cnt, n);
        // printf("vec.size: %d\n", vec->size);

        // find max jump and shorten the path
        int maxJump = 0, jump_Start_Pos = 0, jump_End_Pos = 0, prev = vec->data[0].idx, tmp = end_path[vec->data[0].idx];
        int index[n];
        for(int i = 0; i < n; i++) index[i] = -1;
        for(int i = 0; i < vec->size; i++) index[vec->data[i].idx] = i;
        while(1){
            // printf("watch: %d %d\n", prev, tmp);
            if(index[tmp] != -1){
                if(abs(index[tmp] - index[prev]) > maxJump){
                    maxJump = abs(index[tmp] - index[prev]);
                    jump_Start_Pos = index[prev];
                    jump_End_Pos = index[tmp];
                }
                prev = tmp;
            }
            if(tmp == d) break;
            tmp = end_path[tmp];
        }
        // printf("jump: %d\n", maxJump);
        // printf("watch: %d %d\n", jump_Start_Pos, jump_End_Pos);
        // printf("watch: %d %d\n", vec->data[jump_Start_Pos].idx, vec->data[jump_End_Pos].head);
        records[round_cnt - 1][vec->data[jump_Start_Pos].idx] = vec->data[jump_End_Pos].head;
        vec->data[jump_End_Pos].head = vec->data[jump_Start_Pos].head;
        
        // prune
        expand_arr(&records, &round_cnt, n);
        for(int i = jump_Start_Pos + 1; i < jump_End_Pos; i++){
            records[round_cnt - 1][vec->data[i].idx] = vec->data[i].tail;
            for(int j = 0; j < vec->size; j++){
                if(vec->data[j].head == vec->data[i].tail) vec->data[j].head = vec->data[i].head;
            }
        }
        erase(vec, jump_Start_Pos, jump_End_Pos);
        // printf("after\n");
        // printf("size: %d\n", vec->size);
        // for(int i = 0; i < vec->size; i++){
        //     printf("%d ", vec->data[i].idx);
        // } printf("\n");
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