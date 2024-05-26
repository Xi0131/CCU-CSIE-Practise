#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define debug printf("hi %d\n", __LINE__)
#define watch(x) printf("%s %d\n", #x, x)

int nodes_num, links_num, timeSlots, req_num, ans;

typedef struct {
    int src, dst;
} pair;

typedef struct node {
    int v1, v2, t;
    struct node *left;
    struct node *right;
    struct node *next;
} TreeNode;

typedef struct {
    TreeNode *front, *back;
    int size;
} NodeQueue;

typedef struct {
    int *data;
    int size;
} DynamicVector;

int power(int x, int n){
    if(n == 0) return 1;
    else if(n % 2 == 0) return power(x, n / 2) * power(x, n / 2);
    else return power(x, n - 1) * x;
}

void push_back(DynamicVector *vec, int x) {
    if(vec->size == 0) {
        vec->size++;
        vec->data = (int*) malloc(sizeof(int));
        vec->data[0] = x;
    }
    else {
        vec->size++;
        vec->data = realloc(vec->data, vec->size * sizeof(int));
        vec->data[vec->size-1] = x; 
    }
}

void push_node(NodeQueue *q, TreeNode *node){
    if(q->size == 0) {
        q->size++;
        q->back = node;
        q->front = node;
    }
    else {
        q->size++;
        q->back->next = node;
        q->back = node;
    }
}

TreeNode *pop_node(NodeQueue *q){
    if(q->front == NULL) debug;
    TreeNode *tmp = q->front;
    q->front = q->front->next;
    q->size--;

    return tmp;
}

int **init_time_space(int nodes_num, int timeslots) {
    int **tmp = (int**) malloc(sizeof(int*) * timeslots);
    for(int i = 0; i < timeslots; i++){
        tmp[i] = (int*) malloc(sizeof(int) * nodes_num);
        for(int j = 0; j < nodes_num; j++) tmp[i][j] = 0;
    }
    return tmp;
}

TreeNode *combine_node(TreeNode *left, TreeNode *right) {
    TreeNode *tmp = (TreeNode*) malloc(sizeof(TreeNode));
    tmp->v1 = left->v1;
    tmp->v2 = right->v2;
    tmp->left = left;
    tmp->right = right;
    tmp->t = left->t > right->t ? left->t + 1 : right->t + 1;
    return tmp;
}

TreeNode *create_node(int v1, int v2, int t){
    TreeNode *tmp = (TreeNode*) malloc(sizeof(TreeNode));
    tmp->v1 = v1;
    tmp->v2 = v2;
    tmp->t = t;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->next = NULL;
    return tmp;
}

void bfs(int start, int end, DynamicVector *adj_list, int *req_path){
    // bfs
    int tmp = start;
    int queue[nodes_num], visited[nodes_num], parent[nodes_num];
    int q_front = 0, q_end = 0;
    for(int i = 0; i < nodes_num; i++) visited[i] = 0;
    visited[tmp] = 1;
    while(1){
        if(tmp == end) break;
        for(int i = 0; i < adj_list[tmp].size; i++){
            if(!visited[adj_list[tmp].data[i]]){
                queue[q_end++] = adj_list[tmp].data[i];
                parent[adj_list[tmp].data[i]] = tmp;
                visited[adj_list[tmp].data[i]] = 1;
            }
        }
        tmp = queue[q_front++];
    }
    
    // retrieve path
    q_front = 0, q_end = 0, tmp = end;
    while(tmp != start){
        queue[q_end++] = tmp;
        tmp = parent[tmp];
    }
    queue[q_end] = tmp;

    // store path
    req_path[nodes_num] = q_end + 1;
    for(int i = q_end, j = 0; i >= 0; i--){
        req_path[i] = queue[j++];
    }
}

int valid(int *path, int ***timeSpace, int *nodeMem){
    int valid = 0;
    int linkTime = (int) ceil(log2((double)(path[nodes_num] - 1))) + 1;
    for(int i = 0; i < timeSlots - linkTime; i++){

        // check if basement is valid
        int next_time = 0;
        for(int k = 0; k < path[nodes_num] - 1; k++){
            if(k == 0){
                if((*timeSpace)[i][path[k]] + 1 > nodeMem[path[k]]){
                    next_time = 1;
                    break;
                }
            }
            else {
                if((*timeSpace)[i][path[k]] + 2 > nodeMem[path[k]]){
                    next_time = 1;
                    break;
                }
            }
        }
        if((*timeSpace)[i][path[path[nodes_num]-1]] + 1 > nodeMem[path[path[nodes_num]-1]]) next_time = 1;
        if(next_time) continue;
        
        for(int j = i + 1; j <= i + linkTime; j++){
            int add = power(2, j - (i + 1));
            for(int k = 0; k < path[nodes_num] - 1; k += add){
                if(k == 0){
                    if((*timeSpace)[j][path[k]] + 1 > nodeMem[path[k]]){
                        next_time = 1;
                        break;
                    }
                }
                else {
                    if((*timeSpace)[j][path[k]] + 2 > nodeMem[path[k]]){
                        next_time = 1;
                        break;
                    }
                }
            }
            if((*timeSpace)[j][path[path[nodes_num]-1]] + 1 > nodeMem[path[path[nodes_num]-1]]){
                next_time = 1;
                break;
            }
        }


        // if basement valid, set path
        if(next_time) continue;
        else{
            path[nodes_num+2] = i + 2;
            path[nodes_num+3] = linkTime + 1;
            valid = 1;

            // basement
            for(int k = 0; k < path[nodes_num] - 1; k++){
                if(k == 0){
                    (*timeSpace)[i][path[k]] += 1;
                }
                else (*timeSpace)[i][path[k]] += 2;
            }
            (*timeSpace)[i][path[path[nodes_num]-1]] += 1;

            // swapping
            for(int j = i + 1; j <= i + linkTime; j++){
                int add = power(2, j - (i + 1));
                for(int k = 0; k < path[nodes_num] - 1; k += add){
                    if(k == 0){
                        (*timeSpace)[j][path[k]] += 1;
                    }
                    else (*timeSpace)[j][path[k]] += 2;
                }
                (*timeSpace)[j][path[path[nodes_num]-1]] += 1;
            }
            break;
        }
    }
    return valid;
}

void post_order_traversal(TreeNode *node){
    if(node == NULL) return;
    post_order_traversal(node->left);
    post_order_traversal(node->right);
    if(node->left == NULL && node->right == NULL){
        printf("%d %d %d\n", node->v1, node->v2, node->t);
    }
    else{
        printf("%d %d %d %d %d %d %d\n", node->v1, node->v2, node->left->v1, node->left->v2, node->right->v1, node->right->v2, node->t);
    }
}

int main(){

    scanf("%d %d %d %d", &nodes_num, &links_num, &timeSlots, &req_num);
    int nodeMem[nodes_num];
    pair req[req_num];
    for(int i = 0; i < nodes_num; i++) scanf("%d %d", &i, &nodeMem[i]);
    DynamicVector adj_list[nodes_num];
    for(int i = 0; i < nodes_num; i++) adj_list[i].size = 0;
    for(int i = 0, a, b; i < links_num; i++){
        scanf("%d %d %d", &i, &a, &b);
        push_back(&adj_list[a], b);
        push_back(&adj_list[b], a);
    }
    for(int i = 0; i < req_num; i++) scanf("%d %d %d", &i, &req[i].src, &req[i].dst);

    int **timeSpace = init_time_space(nodes_num, timeSlots);

    // req_path[i][nodes_num] is path size
    // req_path[i][nodes_num + 1] is path id
    // req_path[i][nodes_num + 2] is start time
    // req_path[i][nodes_num + 3] is path duration
    int **req_path = (int**) malloc(req_num * sizeof(int*));
    for(int i = 0; i < req_num; i++){
        req_path[i] = (int*) malloc((nodes_num + 4) * sizeof(int));
        req_path[i][nodes_num + 1] = i;
    }

    // do bfs for all req
    for(int i = 0; i < req_num; i++){
        bfs(req[i].src, req[i].dst, adj_list, req_path[i]);
    }
    
    // sort path base on path size, which is located at req_path[i][nodes_num]
    for(int i = 0; i < req_num; i++){
        for(int j = 0; j < req_num; j++){
            if(req_path[i][nodes_num] < req_path[j][nodes_num]){
                int *pt = req_path[i];
                req_path[i] = req_path[j];
                req_path[j] = pt;
            }
        }
    }

    // check if path is acceptable
    DynamicVector *acID;
    acID = (DynamicVector*) malloc(sizeof(DynamicVector));
    acID->size = 0;
    DynamicVector *acPath;
    acPath = (DynamicVector*) malloc(sizeof(DynamicVector));
    acPath->size = 0;
    for(int i = 0; i < req_num; i++){
        int tmp = valid(req_path[i], &timeSpace, nodeMem);

        if(tmp){
            push_back(acID, req_path[i][nodes_num+1]);
            push_back(acPath, i);
            ans++;

            
            // printf("%d\n", k++);
            // for(int k = 0; k < nodes_num; k++){
            //     printf("%2d ", nodeMem[k]);
            // }
            // printf("\n");
            // for(int k = 0; k < nodes_num; k++){
            //     printf("%2d ", k);
            // }
            // printf("\n");
            // for(int j = timeSlots - 1; j>= 0; j--){
            //     for(int k = 0; k < nodes_num; k++){
            //         printf("%2d ", timeSpace[j][k]);
            //     }
            //     printf("\n");
            // }
            // printf("\n");
        }
    }

    // print result
    printf("%d\n", ans);
    for(int i = 0; i < acPath->size; i++){
        int path = acPath->data[i];
        printf("%d ", acID->data[i]);
        for(int j = 0; j < req_path[path][nodes_num]; j++){
            printf("%d ", req_path[path][j]);
        }
        printf("\n");
        

        // build tree
        NodeQueue *q = (NodeQueue*) malloc(sizeof(NodeQueue));
        q->size = 0;
        int t = req_path[path][nodes_num+2];
        int end = req_path[path][req_path[path][nodes_num]-1];
        for(int j = 0; j < req_path[path][nodes_num] - 1; j++){
            TreeNode *tmp = create_node(req_path[path][j], req_path[path][j+1], t);
            push_node(q, tmp);
        }
        // if(i==16)watch(req_path[path][nodes_num]);
        while(q->size > 1){
            // if(i == 16){
            //     debug;
            //     printf("%d %d\n", q->front->v1, q->front->v2);
            // }
            if(q->front->v2 == end){
                q->back->next = q->front;
                q->back = q->front;
                q->front = q->front->next;
                q->back->next = NULL;
                t++;
            }
            else{
                TreeNode *left_node = pop_node(q);
                TreeNode *right_node = pop_node(q);
                // if(i == 16) printf("%d %d %d %d\n", left_node->v1, left_node->v2, right_node->v1, right_node->v2);
                TreeNode *tmp = combine_node(left_node, right_node);
                push_node(q, tmp);
                if(right_node->v2 == end) t++;
            }
        }

        // printf("%d\n", q->front->v1);
        post_order_traversal(q->front);
        pop_node(q);
        // printf("\n");
    }

    return 0;
}