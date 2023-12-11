#include <stdio.h>

typedef struct{
    int end1, end2;
} linkID;

typedef struct{
    int src, dst;
} reqID;

typedef struct treeNode{
    int val;
    struct treeNode *left;
    struct treeNode *right;
} TreeNode;

int main(){

    int nodes_num, links_num, timeslots, reqs_num;
    scanf("%d %d %d %d", &nodes_num, &links_num, &timeslots, &reqs_num);
    int nodeID[nodes_num];
    linkID link[links_num];
    reqID req[reqs_num];
    for(int i = 0; i < nodes_num; i++) scanf("%d %d", i, nodeID[i]);
    for(int i = 0; i < links_num; i++) scanf("%d %d %d", i, link[i].end1, link[i].end2);
    for(int i = 0; i < reqs_num; i++) scanf("%d %d %d", i, req[i].dst, req[i].src);



    return 0;
}