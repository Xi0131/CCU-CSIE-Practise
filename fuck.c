#include<stdio.h>
#include<stdlib.h>

int main(){
    int path_1[10000], path_2[10000], Node,times=0, record[10000] , a;

    scanf("%d",&Node);

    for(int i=0; i<Node; i++){  //初始化record
        record[i]=-1;
    }

    for(int i=0; i<Node; i++){
        scanf("%d",&path_1[i]);
    }

    for(int i=0; i<Node; i++){
        scanf("%d",&path_2[i]); 
        if(path_2[i]!=-1){        //路徑反向
            record[path_2[i]] = i;
            times++;
        }       
    }

    printf("%d\n", times+2);
    for(int i=0; i<Node; i++){
        printf("%d ", path_1[i]);
    }
    printf("\n");

    a = Node-1;
    while (a != 0)
    {
        path_1[record[a]] = path_2[record[a]];
        for(int i=0; i<Node; i++){
            printf("%d ", path_1[i]);
        }
        printf("\n");
        a = record[a];
    }
    
    for(int i=0; i<Node; i++){
        printf("%d ", path_2[i]);
    }   

    return 0;
}