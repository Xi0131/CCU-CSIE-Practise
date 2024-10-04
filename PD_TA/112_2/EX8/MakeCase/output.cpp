#include<fstream>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 10; //測資筆數

#include <stdlib.h>


struct tNode{
    int data;
    struct tNode *Lchild, *Rchild;
};


void insert(ofstream &foutput, struct tNode *curNode, int newData) {
    if(curNode->data > 0) {
        // printf("%d ", curNode->data);
        foutput << curNode->data << ' ';
    }


    // 1. If the new data is smaller than the data of curNode, the target position is located in the left child.
        // a. If the left child of curNode is NULL, we create a new node for new data and assign it to the left child of curNode.
        // b. Otherwise, if the left child of curNode isn’t NULL, we need to do the same process for the left child and recursively call the insert function. (call the insert function to compare the data of the left child and new data).
    // 2. If the new data is greater than the data of curNode, the target position is located in the right child of curNode. The rest is almost the same.


    //********************** You should write ********************//
    if(curNode->data > newData) {
        // insert data into Lchild
        if(curNode->Lchild == NULL) {
            // create a new node and insert into curNode->Lchild


            struct tNode *newNode = (struct tNode *)malloc(sizeof(struct tNode));
            newNode->data = newData;
            newNode->Lchild = NULL;
            newNode->Rchild = NULL;
            curNode->Lchild = newNode;
            // printf("%d\n", newData);
            foutput << newData << '\n';




        } else {
            // recursively search where to be inserted in curNode->Lchild
            insert(foutput, curNode->Lchild, newData);
        }
    } else if(curNode->data < newData) {
        // insert data into Rchild
        if(curNode->Rchild == NULL) {
            // create a new node and insert into curNode->Rchild
            struct tNode *newNode = (struct tNode *)malloc(sizeof(struct tNode));
            newNode->data = newData;
            newNode->Lchild = NULL;
            newNode->Rchild = NULL;
            curNode->Rchild = newNode;
            // printf("%d\n", newData);
            foutput << newData << '\n';
        } else {
            // recursively search where to be inserted in curNode->Rchild
            insert(foutput, curNode->Rchild, newData);
        }
    } else {
        // error
        exit(1);
    }
    //************************************************************//
}


int find(struct tNode *curNode, int target){
    // If we find the target in curNode, return 1 (i.e. true).
    // If we reach NULL, it means we can't find the target, return 0 (i.e. false).
    // Otherwise, compare the target and the data of curNode to determine the target in which child (either Lchild or Rchild).

    //************************* You should write ***********************//


    if(curNode == NULL) return 0;


    if(curNode->data == target)
        return 1;
    else if(curNode->data > target)
        return find(curNode->Lchild, target);
    else if(curNode->data < target)
        return find(curNode->Rchild, target);
    else {
        // error
        exit(1);
    }
    //******************************************************************//
}


void deleteTree(struct tNode* curNode){
    if (curNode == NULL) return;
    deleteTree(curNode->Lchild);
    deleteTree(curNode->Rchild);
    free(curNode);
}



int n,d;
int t[100100];

void open_file(ifstream &finput,ofstream &foutput,int t_case){
    string dir_path = "../data/secret/";  //資料夾相對路徑

    string input_file_name = to_string(t_case)+".in"; //檔案名稱
    string output_file_name = to_string(t_case)+".ans";
    
    string input_path = dir_path + input_file_name; //開啟檔案位置
    string output_path = dir_path + output_file_name;
    
    finput.open(input_path , ios::in); 
    foutput.open(output_path , ios::out | ios::trunc);
    
    if(!finput){
        cerr << "cannot open input file " << input_path << endl;
        exit(1);
    }
    if(!foutput){
        cerr << "cannot open output file " << output_path << endl;
        exit(1);
    }
}
void solve(ifstream &finput,ofstream &foutput, int t_case){
    int numQuery = 0;
    int tmpNum;
    // scanf("%d", &numQuery);
    finput >> numQuery;


    struct tNode *root = (struct tNode *) malloc(sizeof(struct tNode));
    (*root) = (struct tNode) {.data = 0, .Lchild = NULL, .Rchild = NULL};


    for(int i = 0; i < numQuery; i++) {
        int operation_type, data;
        // scanf("%d%d", &operation_type, &data);
        finput >> operation_type >> data;
        if(operation_type == 1) {
            // insert data
            // To find the target position where to insert, we start from root and compare the data of root and new data.
            insert(foutput, root, data);
        } else if(operation_type == 2) {
            // To determine whether the target data exists in the tree.
            // To find the target data, we start from root and compare the data of root and new data like insert function.
            if(find(root, data)) {
                // printf("%d is in tree\n", data);
                foutput << data << " is in tree\n";
            } else {
                // printf("%d is not in tree\n", data);
                foutput << data << " is not in tree\n";
            }
        }
    }


    // free memory
    deleteTree(root);
}
void close_file(ifstream &finput,ofstream &foutput,int t_case){
    finput.close();
    foutput.close();
}
int main(){
    for(int i=1;i<=N;i++){
        ifstream finput;
        ofstream foutput;
        open_file(finput,foutput,i); //要讀入輸入檔，寫入輸出檔
        solve(finput,foutput,i); //放解答 Code
        close_file(finput,foutput,i); //關閉檔案
    }
}
