#include <stdio.h>
#include <stdlib.h>
#define MAX_NODE 10000
#define MAX_REQ 10000
#define MAX_QUEUE 10000
#define MAX_OUTPUT 10000

#define WALKED -1
#define NOT_WALK 0
#define WALKING 1

#define LINKED 1
#define NOT_LINK 0

#define LEFT_WIN 1
#define RIGHT_WIN 2

#define NO_OUTPUT -1
// struct Node{
//     int mem;
//     int link[2];
// }node[MAX_NODE];

int num_node, num_link, num_timeslot, num_req;
int node[MAX_NODE][MAX_NODE];//save link, 2d
int node_mem[MAX_NODE]; // save every node max mem.
int walked[MAX_NODE];
int bfs_result[MAX_NODE];//index = node, value = where the node from
int bfs_depth[MAX_NODE]={0};
int temp_result[MAX_NODE];
int *result = NULL;
int mem_table[MAX_NODE][MAX_NODE]={0};
int ex_flag=0;
int temp_mem_table[MAX_NODE][MAX_NODE]={0};
int print_node_left=-1, print_node_right=-1;

struct Tree{
    int data;
    int res_index_left;
    int res_index_right;
    int res_left;
    int res_right;
    struct Tree *left;
    struct Tree *right;
};

struct Tree *output_tree[MAX_REQ];
int output_tree_index=0;

struct queue_pair{
    int left_node;
    int right_node;
}print_queue[2];
int print_queue_head=0;
const int print_queue_tail=2;

struct Req{
    int src;
    int dst;
}req[MAX_REQ];

void push(int **tail, int value){
    **tail = value;
    *tail++;
}

void push_queue(int left, int right){
    print_queue[print_queue_head].left_node = left;
    print_queue[print_node_right].right_node = right;
    print_queue_head++;
    return;
}



int is_queue_full(){
    return print_queue_head == print_queue_tail;
}

void clear_queue(){
    print_queue_head=0;
    return;
}

struct Tree* create_node(int res_index_left, int res_index_right){
    struct Tree *temp = (struct Tree*)malloc(sizeof(struct Tree));

    temp->res_index_left = res_index_left;
    temp->res_index_right = res_index_right;
    temp->res_left = result[res_index_left];
    temp->res_right = result[res_index_right];
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Tree* build_tree(int left_index, int right_index, int depth){

    struct Tree* root = NULL;
    int mid_index = (left_index + right_index)/2;
    if(left_index >= right_index) return NULL;

    // if(output_tree[0]==NULL) printf("left: %d, right: %d\n",left_index, right_index);
    root = create_node(left_index, right_index);

    if(right_index - left_index == 1) return root;

    if((right_index - left_index + 1) % 4 == 3 && right_index - left_index != 2) mid_index = mid_index+1;

    // if(right_index-left_index%2 == 1){
    //     root->left = build_tree(left_index, mid_index+1, depth);
    //     root->right = build_tree(mid_index+1, right_index, depth);
    // }else{
    root->left = build_tree(left_index, mid_index, depth);
    root->right = build_tree(mid_index, right_index, depth);
    // }

    return root;
}

int Treedepth(struct Tree *tree){
    int l,r;
    if(tree == NULL) return 0;
    l = Treedepth(tree->left);
    r = Treedepth(tree->right);
    return (l>r ? l+1 : r+1);
}

void free_tree(struct Tree *tree){
    if(tree == NULL) return;

    free_tree(tree->left);
    free_tree(tree->right);

    free(tree);
    return;
}

void post_order(struct Tree* tree, int now_depth){
    if(tree == NULL){
        if(output_tree[0]==NULL) printf("dep: %d\n",now_depth);
         return;
    }

    post_order(tree->left, now_depth-1);
    post_order(tree->right, now_depth-1);

    //放進mem表格，目前+預計要加的+1 <= mem限制
    if((mem_table[now_depth][tree->res_left] + temp_mem_table[now_depth][tree->res_left] + 1 <= node_mem[tree->res_left]) \
         && (mem_table[now_depth][tree->res_right] + temp_mem_table[now_depth][tree->res_right] + 1 <= node_mem[tree->res_right]) ){
        //預計要加的++
        temp_mem_table[now_depth][tree->res_left]++;
        temp_mem_table[now_depth][tree->res_right]++;
    }else{
        ex_flag = 1;
    }
    return;
}

void post_order_print(struct Tree *tree){
    if(tree == NULL) return;

    post_order_print(tree->left);
    post_order_print(tree->right);
    printf("%d %d ", tree->res_left, tree->res_right);
    return;
}

void post_order_print_ex(struct Tree *tree, int now_depth){
    if(tree == NULL || now_depth==1) return;

    post_order_print_ex(tree->left, now_depth-1);
    post_order_print_ex(tree->right, now_depth-1);

    printf("%d %d ", tree->res_left, tree->res_right);
    // if(is_queue_full()){
    //     for(int i=0;i<2;i++){
    //         printf("%d %d ", print_queue[i].left_node, print_queue[i].right_node);
    //     }
    //     clear_queue();
    // }else{
    //     push_queue(tree->res_left, tree->res_right);
    // }
    if(tree->left != NULL && tree->right != NULL){
        printf("%d %d %d %d ",tree->left->res_left, tree->left->res_right, tree->right->res_left, tree->right->res_right);
    }
    printf("%d\n", now_depth);

}

// void level_order_traversal(struct Tree *tree, int now_depth){
//     if(tree == NULL) return;
//     printf("depth: %d\n",now_depth);
//     if(now_depth == 2){
//         printf("%d %d ", tree->res_left, tree->res_right);
//         if(tree->left != NULL && tree->right != NULL){
//             printf("%d %d %d %d ",tree->left->res_left, tree->left->res_right, tree->right->res_left, tree->right->res_right);
//         }
//         printf("%d\n", now_depth);
//     }else if (now_depth>1){
//         level_order_traversal(tree->left, now_depth-1);
//         level_order_traversal(tree->right, now_depth-1);
//     }
//     return;
// }

// void level_order_print_ex(struct Tree *tree){
//     if(tree == NULL) return;
//     int depth = Treedepth(tree);
//     for(int i=depth ; i>1 ; i--){
//         level_order_traversal(tree, i);
//     }
// }



void result_print(int *result){
    while(*result != -1){
        printf("%d ",*result);
        result++;
    }
    printf("\n");
}

void init_walked(){
    for(int i=0;i<MAX_NODE;i++){
        walked[i] = NOT_WALK;
    }
}

void copy_array(int src[], int dst[]){
    for(int i=0;i<MAX_NODE;i++){
        dst[i] = src[i];
    }
}

int *reverse_result(int start, int destination, int depth){
    int *temp = (int *)malloc(sizeof(int) * num_node);
    int now = destination;
    int num = depth - 1;//目前index差
    // printf("dest: %d\n",destination);
    while(now!=start){//還沒走回去
        temp[num] = now;
        // printf("temp_id: %d ",num);
        // printf("temp: %d\n",temp[num]);
        num--;
        now = bfs_result[now];//walk back;
    }
    temp[num] = now;
    temp[depth] = -1;
    // printf("temp_values: ");
    //     for(int j=0;j<depth;j++){
    //         printf("%d ",temp[j]);
    //     }
    //     printf("\n");
    return temp;

}

// int compare_tieresult(int a[], int b[], int start, int destination, int left_depth){
//     int trace_a = destination;
//     int trace_b = destination;
//     int rt=-1;
//     if(left_depth < depth) return LEFT_WIN;
//     while(trace_a!=start && trace_b!=start){
//         int left,right;
//         left = trace_a;
//         right = trace_b;
//         if(left < right){
//             rt = LEFT_WIN;
//         }else if(right < left){
//             rt = RIGHT_WIN;
//         }
//         trace_a = a[trace_a];
//         trace_b = b[trace_b];
//     }
//     return rt;
// }


void BFS(int start, int destination){
    int queue[MAX_QUEUE];
    queue[0]=start;
    int head=0, tail=1;
    int flag = 0;

    while(head!=tail){

       bfs_depth[queue[head]] = (bfs_depth[queue[head]]) ? bfs_depth[queue[head]] : 1;//start 的 depth = 1
        //檢查與 head 相連的 NOT_WALK node
        for(int i=0;i<num_node;i++){
            int near = i;
            //printf("near: %d\n", near);
            if(node[queue[head]][near]==LINKED && walked[near] == NOT_WALK){
                //紀錄queue
                bfs_result[near] = queue[head];//紀錄 i 從 head 來
                //printf("bfs_result: %d\n", bfs_result[near]);
                bfs_depth[near] = bfs_depth[queue[head]] + 1;//紀錄 i 的 depth

                queue[tail] = near;
                tail++;
                //printf("tail: %d\n",queue[tail-1]);
                walked[i] = WALKING;

                if(near == destination){//走到目的地
                    // if(flag){//存在 tie
                    //     //比較 tie 的
                    //     int result = compare_tieresult(bfs_result, temp_result, start, destination, bfs_depth[near]);
                    //     if(result == -1){
                    //         printf("Something wrong\n");
                    //     }else if(result == LEFT_WIN){
                    //         copy_array(bfs_result, temp_result);
                    //     }
                    // }else{//第一個有結果
                    // //存一份temp
                    //     flag=1;
                    //     copy_array(bfs_result, temp_result);
                    // //紀錄當前深度
                    //     depth = bfs_depth[near];
                    // }
                    flag = 1;
                    break;
                }
                // push(&tail, near);//push to queue

            }
        }

        if(flag){ //處理 tie
            break;
        }
        walked[queue[head]] = WALKED;
        head++;
    }
    return;
}

void init_bfs(){
    init_walked();
    for(int i=0;i<num_node;i++){
        bfs_depth[i] = 0;
        bfs_result[i] = -1;
    }
}


int main(){
    //init
    // int num_node, num_link, num_timeslot, num_req;
    scanf("%d %d %d %d", &num_node, &num_link, &num_timeslot, &num_req);

    int dummy;

    //input basic data
    for(int i=0 ; i < num_node ; i++){
        scanf("%d %d",&dummy, &node_mem[i]);
    }
    //init node[][]
    for(int i=0;i<MAX_NODE;i++){
        for(int j=0;j<MAX_NODE;j++){
            node[i][j]=NOT_LINK;
        }
    }
    //input node[][]
    for(int i=0 ; i < num_link ; i++){
        int a,b;
        // scanf("%d %d %d",&dummy, &(node[i].link[0]), &(node[i].link[1]));
        scanf("%d %d %d",&dummy, &a, &b);
        node[a][b]=LINKED;
        node[b][a]=LINKED;
    }
    // for(int i=0;i<MAX_NODE;i++){
    //     for(int j=0;j<MAX_NODE;j++){
    //        printf()
    //     }
    // }
    //input req
    for(int i=0; i < num_req; i++){
        scanf("%d %d %d", &dummy, &req[i].src, &req[i].dst);
    }

    init_walked();
    int element;
    int output_id[MAX_OUTPUT];
    int output_id_index=0;
    int *output_result[MAX_OUTPUT];
    int output_result_index = 0;
    struct Tree *tree;
    for(int i=0; i<num_req ; i++){
        //printf("req: %d %d\n", req[i].src, req[i].dst);
        BFS(req[i].src, req[i].dst);
        // printf("bfs: ");
        // for(int j=0;j<num_node;j++){
        //     printf("%d ",bfs_result[j]);
        // }
        // printf("\n");
        //處理bfs_result
        element = bfs_depth[req[i].dst];
        //printf("element: %d\n",element);

        result = reverse_result(req[i].src, req[i].dst, element);
        // printf("result: ");
        // for(int j=0;j<element;j++){
        //     printf("%d ",result[j]);
        // }
        // printf("\n");
        //建樹

        tree = build_tree(0,element-1,element);
        int depth = Treedepth(tree);
        //if(i==33) printf("i=33: %d\n",depth);
        if(depth> num_timeslot){
            free_tree(tree);
             continue;
        }

        
        //放進 temp 的 mem，更新ex_flag;
        //printf("hihi\n");
        post_order(tree, depth);
        //printf("haha\n");
        //判斷是否足夠mem
        if(ex_flag){//沒有
            for(int j=0;j<num_timeslot;j++){
                for(int k=0;k<num_node;k++){
                    temp_mem_table[j][k]=0;
                }
            }
            free_tree(tree);
        }else{//有，temp 加過去
            for(int j=0;j<num_timeslot;j++){
                for(int k=0;k<num_node;k++){
                    mem_table[j][k] += temp_mem_table[j][k];
                    temp_mem_table[j][k]=0;
                }
            }
            //save tree
            output_tree[output_tree_index++] = tree;
            //printf("p: %p",output_tree[output_tree_index-1]);
            output_id[output_id_index++] = i;
            output_result[output_result_index++] = result;
            // printf("result: ");
            // for(int j=0;j<depth;j++){
            //     printf("%d ",result[j]);
            // }
            // printf("\n");
        }
        if(ex_flag==0){
            printf("%d\n",i);
            for(int k=0;k<num_node;k++){
                    printf("%d ",k%10);
                }
            printf("\n");
            for(int j=0;j<num_timeslot;j++){
                for(int k=0;k<num_node;k++){
                    printf("%d ",mem_table[j][k]);
                }
                printf("\n");
            }
        }
        //各種初始化
            //free tree
        //free_tree(tree);
        // free(result);
            //init walk
        init_bfs();
        ex_flag = 0;
    }
    //輸出
    // for(int i=0;i<20;i++){
    //     printf("tree: %p\n",output_tree[i]);
    // }



    printf("%d\n", output_tree_index);
    for(int i=0;i<output_tree_index;i++){
        struct Tree *now_tree = output_tree[i];
        printf("%d ", output_id[i]);
        //純print poster-order
        result_print(output_result[i]);
        post_order_print_ex(now_tree, Treedepth(now_tree)+1);

    }

    return 0;
}