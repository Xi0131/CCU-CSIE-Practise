#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, Maze[600][600], Src1x, Src1y, Src2x, Src2y, Dst1x, Dst1y, Dst2x, Dst2y;

#define debug printf("hi %d\n", __LINE__);

typedef struct Node{
    int x, y;
    struct Node* next;
   // int route[600][600]; 
} Node;


// 定義佇列結構，包含首尾節點指標
typedef struct Queue {
    struct Node* front;
    struct Node* rear;
}Queue;

// 初始化一個空佇列
struct Queue* createQueue() {
    debug;
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// 檢查佇列是否為空
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// 將元素加入佇列的尾端
void enqueue(Queue* queue, int i, int j){
        Node* newNode=(Node*)malloc(sizeof(Node));
        newNode->x=i;
        newNode->y=j;
        newNode->next= NULL;

        if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } 
        else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

}

// 從佇列的前端取出元素
void dequeue(Queue* queue, int* i, int* j){
    if(!isEmpty(queue)){
        (*i) = queue->front->x;
        (*j) = queue->front->y;
        Node* temp = queue->front;
        queue->front = temp->next;
        free(temp);
    }
}


void bfs(int Src1x, int Src1y, int Src2x, int Src2y, int Dst1x, int Dst1y){    //int  Dst2x,int  Dst2y
    debug;
    int visit[500][500];
    int parent[500][500];
    Queue* queue = createQueue();

    parent[Src1x][Src1y]=-1;
    parent[Src2x][Src2y]=-1;
    memset(visit,0,sizeof(visit));

    enqueue(queue,Src1x,Src1y);
    
    while (!isEmpty(queue)){
        // debug;
        
        int x,y;
        dequeue(queue, &x, &y);
        visit[x][y] = 1;
        if(x == Dst1x && y == Dst1y){
            break;
        }

        //up
        if(!Maze[x][y+1] && !visit[x][y+1]){
            enqueue(queue, x, y+1);
            parent[x][y+1]=0;
        }
        
        //right
        if(!Maze[x+1][y] && !visit[x+1][y]){
            enqueue(queue, x+1, y);
            parent[x+1][y]=1;
        }

        //down
        if(!Maze[x][y-1] && !visit[x][y-1]){
            enqueue(queue, x, y-1);
            parent[x][y-1]=2;
        }

        //left
        if(!Maze[x-1][y] && !visit[x-1][y]){
            enqueue(queue, x-1, y);
            parent[x-1][y]=3;
        }
        
    }   
    debug;
    int temp_x = Dst1x, temp_y = Dst1y;
    int step[2500], i = 0;
    while(parent[temp_x][temp_y]!=-1){
        // printf("%d %d\n", temp_x, temp_y);
        // printf("%d ",parent[temp_x][temp_y]);
        step[i] = parent[temp_x][temp_y];
        i++;

        if(parent[temp_x][temp_y] == 0) 
            temp_y = temp_y-1;

        else if(parent[temp_x][temp_y] == 1) 
            temp_x = temp_x-1;

        else if(parent[temp_x][temp_y] == 2) 
            temp_y = temp_y+1;

        else if(parent[temp_x][temp_y] == 3) 
            temp_x = temp_x+1;
    }
    i--;
    for(; i >= 0; i--){
        printf("%d", step[i]);
    }
}


int main()
{
    scanf("%d",&n);
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            scanf("%d",&Maze[j][i]);
        }  
    }
    scanf("%d %d %d %d %d %d %d %d",&Src1x, &Src1y, &Src2x, &Src2y, &Dst1x, &Dst1y, &Dst2x, &Dst2y);
    debug;
    bfs(Src1x, Src1y, Src2x, Src2y, Dst1x, Dst1y);
    debug;
    

    //Node* head1 = initialize_queue(Src1x,Src1y);
    //Node* head1;

    return 0;
}