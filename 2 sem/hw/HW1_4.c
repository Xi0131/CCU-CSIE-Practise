#include <stdio.h>
#include <string.h>
#include <string.h>

int main(){

    char *words[100000];
    // for(int i = 0; i < 100000; i++){
    //     words[i] = (char*) malloc(sizeof(char) * 100);
    //     scanf("%s", words[i]);
    // }
    int ans = 0;
    int next = 0;
    char buffer;
    do{
        words[next] = (char*) malloc(sizeof(char) * 100);
        scanf("%s", words[next]);
        next++;
    }while(buffer = getchar() != '\n');
    char target[100];
    scanf("%s", target);
    int t_len = strlen(target);
    for(int i = 0; i <= next; i++){
        if(strlen(*words[i]) == t_len){
            int flag = 1;
            for(int j = 0; j <= t_len; j++){
                if(*words[i] != target[j]) flag = 0;
            }
            if(flag) ans++;
        }
    }

    return 0;
}