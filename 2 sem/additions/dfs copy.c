#include <stdio.h>
#include <stdlib.h>

#define debug printf("debug line %d", __LINE__)

struct node{
    int vertex;
    struct node *next;
};

struct graph{
    int vertex;
    int *visited;
    struct node **list;
};

struct node* create_node(int n){
    struct node* new_node;
    new_node->vertex = n;
    new_node->next = NULL;
    return new_node;
};

struct graph* create_graph(int n){
    struct graph *init = (struct graph*) malloc(sizeof(struct graph));

    init->list = (struct node**) malloc(sizeof(struct node*) * n);

    init->visited = (int*) malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        init->list[i] = NULL;
        init->visited[i] = 0;
    }

    return init;
};

struct graph* add_edge(struct graph* graph, int x, int y){

    struct node* new_node = create_node(y);
    new_node->vertex = y;
    new_node->next = graph->list[x];

    new_node = create_node(x);
    new_node->vertex = x;
    new_node->next = graph->list[y];
};

int DFS(struct graph* graph, int vertex) {
  struct node* adjList = graph->list[vertex];
  struct node* temp = adjList;

  graph->visited[vertex] = 1;
  printf("Visited %d \n", vertex);

  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) {
      DFS(graph, connectedVertex);
    }
    else {
        printf("YES");
        return 1;
    }
    temp = temp->next;
  }
  return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    struct graph* graph = create_graph(n);

    for(int i = 0; i < n; i++){
        int x, y;
        char *c;
        scanf("%d", &x);
        do{
            scanf("%d %c", &y, c);
            add_edge(graph, x, y);
            debug;
            printf("hi");
        }while(*c != '\n' || *c != EOF);
    }

    int flag = 0;
    for(int i = 0; i < n; i++){
        flag = 0;
        if(DFS(graph, i)) break;
        flag = 1;
    }
    if(flag) printf("NO");

    return 0;
}
