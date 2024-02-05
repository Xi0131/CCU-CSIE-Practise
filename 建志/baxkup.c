#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define debug printf("hi\n")

int Nodes, Links, TimeSlots, Req;

typedef struct Pair
{
    int v1, v2;
    struct Pair *next;
} pair;

typedef struct
{
    pair *front, *end;
    int size;
} PairQueue;

pair *create_node(int v1, int v2){
    pair *tmp = (pair*) malloc(sizeof(pair));
    tmp->v1 = v1;
    tmp->v2 = v2;
    tmp->next = NULL;
    return tmp;
}

void push_node(PairQueue *q, pair *node) {
    if(q->size == 0) {
        q->size++;
        q->end = node;
        q->front = node;
    }
    else {
        q->size++;
        q->end->next = node;
        q->end = node;
    }
}

pair *pop_node(PairQueue *q) {
    pair *tmp = q->front;
    q->front = q->front->next;
    q->size--;

    return tmp;
}

int power(int a, int b) {
    int temp = a;
    if(b == 0) return 1;
    for(int i = 1; i < b; i++) a = a * temp;
    return a;
}

int* BFS(int Nodes, int **graph, int src, int dst) {
    // 標記所有節點為未訪問
    int visited[Nodes];
    int parent[Nodes];
    int queue[Nodes];
    int q_front = 0, q_tail = 0;
    int size = 0;

    int *record = (int*) malloc((Nodes + 2) * sizeof(int));

    for (int i = 0; i < Nodes; i++)
    {
        visited[i] = 0;
    }
    
    // 創建一個隊列，並將起始節點入隊
    visited[src] = 1;
    queue[q_tail++] = src;
    // 開始進行廣度優先搜索
    while (1) {
        // 出隊一個節點，並打印
        int temp = queue[q_front++];
        if (temp == dst) break;
        else{
        // 對該節點的所有相鄰節點進行處理
            for (int i = 1; i <= graph[temp][0]; ++i) {
                if (!visited[graph[temp][i]]) {
                    queue[q_tail++] = graph[temp][i];
                    parent[graph[temp][i]] = temp;
                    visited[graph[temp][i]] = 1;
                }
            }
        }
    }
    q_tail = 0;
    q_front = 0;
    int temp = dst;
    while (1)
    {
        if (temp != src)
        {
            queue[q_tail++] = temp;
            temp = parent[temp];
        }
        else break;
    }
    record[q_front++] = src;
    while (1)
    {
        if (q_tail != 0)
        {
            record[q_front++] = queue[--q_tail];
            size++;
        }
        else break;
    }
    record[q_front++] = dst;

    record[Nodes] = size + 1;

    return record;
}

int valid(int *path, int ***time, int *QuantumMemory) {
    int next_time = 0;
    int exp = 0;
    // for(int i = 0; i < path[Nodes]; i++){
    //     printf("%d ", path[i]);
    // }printf("\n");
    for (int j = 1; j < TimeSlots; j++)
    {
        int acc = power(2, exp++);
        for (int k = 0; k < path[Nodes]; k += acc)
        {
            if(k == 0){
                if((*time)[j][path[k]] + 1 > QuantumMemory[path[k]]){
                    next_time = 1;
                    // printf("fail\n");
                    break;
                }
            }
            else {
                if((*time)[j][path[k]] + 2 > QuantumMemory[path[k]]){
                    next_time = 1;
                    // printf("fail\n");
                    break;
                }
            }
        }
        if(acc + 1 >= path[Nodes]){
            break;
        }
        if((*time)[j][path[path[Nodes]-1]] + 1 > QuantumMemory[path[path[Nodes]-1]]) next_time = 1;
    }
    if(next_time) return 0;
    // printf("succ\n");

    // for(int i = 0; i < path[Nodes]; i++){
    //     printf("%d ", path[i]);
    // }printf("\n");
    exp = 0;
    for(int j = 1; j < TimeSlots; j++){
        int acc = power(2, exp++);
        for (int k = 0; k < path[Nodes] - 1; k += acc)
        {
            if(k == 0){
                (*time)[j][path[k]] += 1;
            }
            else (*time)[j][path[k]] += 2;

        }
        if(acc + 1 >= path[Nodes]){
            break;
        }
        (*time)[j][path[path[Nodes]-1]] += 1;
    }

    // for(int j = 0; j < Nodes; j++){
    //     printf("%2d ", QuantumMemory[j]);
    // }printf("\n");
    // for(int j = TimeSlots - 1; j >= 0; j--){
    //     for(int k = 0; k < Nodes; k++){
    //         printf("%2d ", (*time)[j][k]);
    //     }
    //     printf("\n");
    // }

    return 1;
}

int main(){
    
    scanf("%d%d%d%d", &Nodes, &Links, &TimeSlots, &Req);
    int QuantumMemory[Nodes];
    int Request[Req][2];
    int **list = (int**) malloc(Nodes * sizeof(int*));
    for(int i = 0; i < (Nodes + 1); i++){
        list[i] = (int*) malloc((Nodes + 1)* sizeof(int));
    }
    
    for (int i = 0; i <Nodes; i++)
    {
        list[i][0] = 0;
    }

    for (int i = 0; i < Nodes; i++)
    {
        scanf("%d %d", &i, &QuantumMemory[i]);
    }
    for (int i = 0; i < Links; i++)
    {
        int a, b;
        scanf("%d %d %d", &i, &a, &b);
        list[a][++list[a][0]] = b;
        list[b][++list[b][0]] = a;
    }

    // for(int i = 0; i < Nodes; i++){
    //     printf("%d ", list[i][0]);
    // }
    // printf("hi\n");

    // for(int k = 0; k < Nodes; k++){
        for (int i = 0; i < Nodes; i++) {
        int j = list[i][0];
            while (j > 0 && list[i][j - 1] > list[i][j]) {
                int temp = list[i][j];
                list[i][j] = list[i][j - 1];
                list[i][j - 1] = temp;
                j--;
            }
        }
    // }

    // for (int i = 0; i < Nodes; i++) {
    //     printf("%d : ", list[i][0]);
    //     for(int j = 0; j < list[i][0]; j++){
    //         printf("%d ", list[i][j]);
    //     } printf("\n");
    // }

    for (int i = 0; i < Req; i++)
    {
        scanf("%d %d %d",&i, &Request[i][0], &Request[i][1]);
    }

    int **p_r = (int**) malloc(Req * sizeof(int*));
    //p_r[i][Nodes] is sizeof path
    for (int i = 0; i < Req; i++)
    {
        p_r[i] = BFS(Nodes, list, Request[i][0], Request[i][1]);
        p_r[i][Nodes + 1] = i;
    }

    // enhancement
    for (int i = 0; i < Req; i++) {
    int j = i;
        while (j > 0 && p_r[j - 1][Nodes] > p_r[j][Nodes]) {
            int* temp = p_r[j];
            p_r[j] = p_r[j - 1];
            p_r[j - 1] = temp;
            j--;
        }
    }
    
    // for (int i = 0; i < Req; i++)
    // {
    //     printf("size %d\n", p_r[i][Nodes]);
    //     for (int j = 0; j < p_r[i][Nodes]; j++)
    //     {
    //         printf("%d ", p_r[i][j]);
    //     }
    //     printf("\n");
    // }

    int **time = (int**) malloc(TimeSlots * sizeof(int*));
    for (int i = 0; i < TimeSlots; i++)
    {
        time[i] = (int*) malloc(Nodes * sizeof(int));
        for(int j = 0; j < Nodes; j++) time[i][j] = 0;
    }

    int* req_queue[Nodes];
    // int **req_queue = (int**) malloc(Req * sizeof(int*));
    int q_end = 0, q_front = 0, ans = 0;
    for (int i = 0; i < Req; i++)
    {
        if(valid(p_r[i], &time, QuantumMemory)){
            ans++;
            req_queue[q_end++] = p_r[i];
        }
        // for(int j = 0; j < Nodes; j++){
        //     printf("%2d ", QuantumMemory[j]);
        // }printf("\n");
        // for(int j = TimeSlots - 1; j >= 0; j--){
        //     for(int k = 0; k < Nodes; k++){
        //         printf("%2d ", time[j][k]);
        //     }
        //     printf("\n");
        // }
    }

    printf("%d\n", ans);
    while (q_front != q_end)
    {
        printf("%d ", req_queue[q_front][Nodes + 1]);
        for (int j = 0; j < req_queue[q_front][Nodes] && q_front != q_end; j++)
        {
            printf("%d ", req_queue[q_front][j]);
        }
        printf("\n");

        PairQueue *q = (PairQueue*) malloc(sizeof(PairQueue));
        q->size = 0;
        int t = 2;
        int end = req_queue[q_front][req_queue[q_front][Nodes] - 1];
        for (int j = 0; j < req_queue[q_front][Nodes] - 1; j++)
        {
            pair *tmp = create_node(req_queue[q_front][j], req_queue[q_front][j+1]);
            printf("%d %d %d\n", req_queue[q_front][j], req_queue[q_front][j+1], t);
            push_node(q, tmp);            
        }
        t++;
        while (q->size > 1)
        {
            if(q->front->v2 == end){
                q->end->next = q->front;
                q->end = q->front;
                q->front = q->front->next;
                q->end->next = NULL;
                t++;
            }
            else{
                pair *left_node = pop_node(q);
                pair *right_node = pop_node(q);
                printf("%d %d %d %d %d %d %d\n", left_node->v1, right_node->v2, left_node->v1, left_node->v2, right_node->v1, right_node->v2, t);
                pair *tmp = create_node(left_node->v1, right_node->v2);
                push_node(q, tmp);
                if(right_node->v2 == end) t++;
            }
        }

        q_front++;
    }

    
}