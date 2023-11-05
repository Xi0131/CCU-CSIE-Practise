#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    int size = 1, flag = 0;
    char str[1001][1001];
    char tmp[1001];
    scanf("%s ", str[0]);
    while(scanf("%s", tmp) != EOF){
        if(tmp[strlen(tmp) - 1] == 26) tmp[strlen(tmp) - 1] = '\0';
        for(int i = 0; i < size; i++){
            if(!strcmp(tmp, str[i])){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            strcpy(str[size], tmp);
            size++;
        }
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < strlen(str[i]); j++){
            str[i][j] = tolower(str[i][j]);
        }
        printf("%s", str[i]);
        if(i != size - 1) printf(" ");
        else printf("\n");
    }
    // printf("%d", str[size-1][strlen(str[size-1]) - 1]);

    return 0;
}