#include <stdio.h>
#include <stdlib.h>

#define debug printf("hi\n")

int Nodes, Links, TimeSlots, Req;


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

    for(int k = 0; k < Nodes; k++){
        for (int i = 0; i < list[k][0]; i++) {
        int j = i;
            while (j > 0 && list[k][j-1] > list[k][j]) {
                int temp = list[k][j];
                list[k][j] = list[k][j];
                list[k][j] = temp;
                j--;
            }
        }
    }
}