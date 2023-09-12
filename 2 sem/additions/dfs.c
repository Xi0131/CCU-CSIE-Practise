#include <stdio.h>
#include <stdlib.h>

struct AdjListNode{
    int dest;
    struct AdjListNode *next;
};

struct AdjList{
    struct AdjListNode *head;
};

typedef struct Graph{
    int v_num;
    struct AdjList *vertices;
} Graph;

void init_graph(struct Graph *graph, int vert){
    graph->v_num = vert;
    graph->vertices = (int*) malloc(sizeof(int) * vert);
}

struct AdjListNode* addNode(int dest){
    struct AdjListNode *new_node = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    new_node->dest = dest;
    new_node->next = NULL;
    return new_node;
}

int isCycle(){

    return 0;
}

int add_edge(struct Graph *graph, int src, int dest){

    struct AdjListNode *check = NULL;
    struct AdjListNode *newNode = addNode(dest);    
    graph->vertices[src];
    if (graph->vertices[src].head == NULL) {
        newNode->next = graph->vertices[src].head;
        graph->vertices[src].head = newNode;
    }
    else {
 
        check = graph->vertices[src].head;
        while (check->next != NULL) {
            check = check->next;
        }
        check->next = newNode;
    }
}

int main(){

    int n;
    Graph graph;
    scanf("%d", &n);
    init_graph(&graph, n);
    int visited[n];
    int restack[n];
    for(int i = 0; i < n; i++){
        visited[i] = 0;
        restack[i] = 0;
    }

    for(int i = 0; i < n; i++){
        int x;
        int num;
        scanf("%d", &x);
        int arr[n];
        for(int i = 0; i < n; i++) arr[i] = 0;
        while(scanf("%d", &num) != EOF){
            int space = getchar();
            arr[num] = 1;
            if(space == '\n') break;
        }
    }

    return 0;
}