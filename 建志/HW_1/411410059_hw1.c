#include<stdio.h>
#include<stdlib.h>

#define debug printf("hi %d\n", __LINE__);

int sz, ball_x1, ball_y1, ball_x2, ball_y2, exit_a1, exit_b1, exit_a2, exit_b2;
int ori_map[501][501];

typedef struct double_linked_list{
    int x; // also be used to store steps
    int y;
    int size; // for queue, true size will be maintained in the first and last node
    struct double_linked_list *next;
    struct double_linked_list *prev;
    struct double_linked_list *tail; // for queue
} dll;

typedef struct pair{
    int x;
    int y;
} pair;

typedef struct linked_list{
    int n;
    int size;
    struct linked_list *next;
    struct linked_list *prev;
} llist;

llist *push_front(llist *list, int direct){
    llist *tmp = (llist*) malloc(sizeof(llist));
    tmp->n = direct;
    printf("%d\n", tmp->n);
    tmp->prev = NULL;
    if(list == NULL){
        tmp->size = 1;
        tmp->next = NULL;
    }
    else{
        tmp->size = ++list->size;
        list->prev = tmp;
        tmp->next = list;
    }
    list = tmp;
    if(list == NULL) debug;
    return list;
}

dll *q_push(dll *queue, int new_x, int new_y){
    dll *tmp = (dll*) malloc(sizeof(dll));
    tmp->x = new_x;
    tmp->y = new_y;
    tmp->next = NULL;
    if(queue == NULL){
        tmp->tail = tmp;
        tmp->prev = NULL;
        tmp->size = 1;
        queue = tmp;
    }
    else{
        tmp->prev = queue->tail;
        queue->tail->next = tmp;
        queue->tail = tmp;
        queue->size++;
        tmp->size = queue->size;
    }
    return queue;
}

dll *q_pop(dll *queue){
    if(queue != NULL){
        dll *tmp = queue;
        queue = tmp->next;
        if(queue != NULL){
            queue->prev = NULL;
            queue->tail = tmp->tail;
            queue->size = tmp->size - 1;
        }
        free(tmp);
    }
    return queue;
}

void q_clear(dll *queue){
    while(queue != NULL){
        dll *tmp = queue;
        queue = tmp->next;
        free(tmp);
    }
}

void bfs(pair **parent, int x, int y, int des_x, int des_y){
    parent[x][y] = (pair) {0, 0};
    int map_visited[501][501];
    dll *queue = NULL;
    queue = q_push(queue, x, y);
    while(queue != NULL){
        dll *q_tmp = queue;
        printf("%d %d\n", q_tmp->x, q_tmp->y);
        if(ori_map[q_tmp->x - 1][q_tmp->y] != 1 && map_visited[q_tmp->x - 1][q_tmp->y] != 1){
            // debug;
            queue = q_push(queue, q_tmp->x - 1, q_tmp->y); // up
            parent[q_tmp->x - 1][q_tmp->y] = (pair) {q_tmp->x, q_tmp->y};
        }
        if(ori_map[q_tmp->x][q_tmp->y + 1] != 1 && map_visited[q_tmp->x][q_tmp->y + 1] != 1){
            // debug;
            queue = q_push(queue, q_tmp->x, q_tmp->y + 1); // right
            parent[q_tmp->x][q_tmp->y + 1] = (pair) {q_tmp->x, q_tmp->y};
        }
        if(ori_map[q_tmp->x + 1][q_tmp->y] != 1 && map_visited[q_tmp->x + 1][q_tmp->y] != 1){
            // debug;
            queue = q_push(queue, q_tmp->x + 1, q_tmp->y); // down
            parent[q_tmp->x + 1][q_tmp->y] = (pair) {q_tmp->x, q_tmp->y};
        }
        if(ori_map[q_tmp->x][q_tmp->y - 1] != 1 && map_visited[q_tmp->x][q_tmp->y - 1] != 1){
            // debug;
            queue = q_push(queue, q_tmp->x, q_tmp->y - 1); // left
            parent[q_tmp->x][q_tmp->y - 1] = (pair) {q_tmp->x, q_tmp->y};
        }
        
        if(q_tmp->x == des_x && q_tmp->y == des_y){
            break;
        };
        map_visited[q_tmp->x][q_tmp->y] = 1;
        map_visited[x][y] = 1;
        queue = q_pop(queue);
    }
    q_clear(queue);
}

llist *extract_step(pair **parent, llist *steps, int dest_x, int dest_y){
    debug;
    while(parent[dest_x][dest_y].x != 0 && parent[dest_x][dest_y].y != 0){
        if(parent[dest_x][dest_y].x > dest_x) steps = push_front(steps, 0); // up
        if(parent[dest_x][dest_y].y < dest_y) steps = push_front(steps, 1); // right
        if(parent[dest_x][dest_y].x < dest_x) steps = push_front(steps, 2); // down
        if(parent[dest_x][dest_y].y > dest_y) steps = push_front(steps, 3); // left
        int tmp_x = dest_x, tmp_y = dest_y;
        dest_x = parent[tmp_x][tmp_y].x;
        dest_y = parent[tmp_x][tmp_y].y;
    }
    return steps;
}

void stimulate(llist *steps, int *pos_x, int *pos_y){
    debug;
    llist *tmp = steps;
    if(tmp == NULL) debug;
    do{
        debug;
        printf("%d\n", tmp->n);
        printf("%d %d\n", *pos_x, *pos_y);
        if(tmp->n == 0 && ori_map[*pos_x - 1][*pos_y] != 1) (*pos_x)--;
        if(tmp->n == 1 && ori_map[*pos_x][*pos_y + 1] != 1) (*pos_y)++;
        if(tmp->n == 2 && ori_map[*pos_x + 1][*pos_y] != 1) (*pos_x)++;
        if(tmp->n == 3 && ori_map[*pos_x][*pos_y - 1] != 1) (*pos_y)--;
        tmp = tmp->next;
    } while(tmp != NULL);
    debug;
}

void print_direct(llist *steps){
    llist *tmp = steps;
    do{
        printf("%d ", tmp->n);
        tmp = tmp->next;
    } while(tmp != NULL);
}

// void print_parent(pair **parent, int x, int y){
//     while(parent[x][y].x != 0){
//         printf("parent of %d %d : %d %d\n", x, y, parent[x][y].x, parent[x][y].y);
//         // printf("see %d %d : %d %d\n", x, y, parent[x][y].x, parent[x][y].y);
//         printf("%d %d\n", parent[x][y].x, parent[x][y].y);
//         x = parent[x][y].x;
//         y = parent[x][y].y;
//         printf("%d %d\n", x, y);
//     }
// }

int main(){

    scanf("%d %d %d %d %d %d %d %d %d", &sz, &ball_x1, &ball_y1, &ball_x2, &ball_y2, &exit_a1, &exit_b1, &exit_a2, &exit_b2);
    ball_x1 = sz - ball_x1 - 1;
    ball_x2 = sz - ball_x2 - 1;
    for(int i = 0; i < sz; i++){
        for(int j = 0; j < sz; j++){
            scanf("%d", &ori_map[i][j]);
        }
    }

    pair **parent = (pair**) malloc(sz * sizeof(pair*));
    for(int i = 0; i < sz; i++) parent[i] = (pair*) malloc(sz * sizeof(pair));
    for(int i = 0; i < sz; i++){
        for(int j = 0; j < sz; j++){
            parent[i][j] = (pair) {0, 0};
        }
    }
    llist *steps_v1_first = NULL, *steps_v1_second = NULL, *steps_v2_first = NULL, *steps_v2_second = NULL;
    // 1.1
    bfs(parent, ball_x1, ball_y1, exit_a1, exit_b1);
    debug;
    int new_x2 = ball_x2, new_y2 = ball_y2;
    steps_v1_first = extract_step(parent, steps_v1_first, exit_a1, exit_b1);
    debug;
    stimulate(steps_v1_first, &new_x2, &new_y2);
    debug;
    
    // 1.2
    bfs(parent, new_x2, new_y2, exit_a2, exit_b2);
    debug;
    steps_v1_second = extract_step(parent, steps_v1_second, exit_a2, exit_b2);

    // 2.1
    bfs(parent, ball_x2, ball_y2, exit_a1, exit_b1);
    int new_x1 = ball_x1, new_y1 = ball_y1;
    steps_v2_first = extract_step(parent, steps_v2_first, exit_a1, exit_b1);
    debug;
    stimulate(steps_v2_first, &new_x1, &new_y1);

    // 2.2
    bfs(parent, new_x1, new_y1, exit_a2, exit_b2);
    steps_v2_second = extract_step(parent, steps_v2_second, exit_a2, exit_b2);

    debug;
    if(steps_v1_first == NULL) debug;
    if(steps_v1_second == NULL) debug;
    if(steps_v2_first == NULL) debug;
    if(steps_v2_second == NULL) debug;
    printf("%d %d %d %d", steps_v1_first->size, steps_v1_second->size, steps_v2_first->size, steps_v2_second->size);
    if(steps_v1_first->size < steps_v2_first->size){
        
    }

    return 0;
}