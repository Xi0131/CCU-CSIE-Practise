#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>

#define watch(x) printf("%s is %c\n", (#x), (x))
#define debug printf("HI\n")

int main(){

    char *words[100000];
    int ans = 0;
    int cnt = 0;
    char buffer;
    do{
        words[cnt] = (char*) malloc(sizeof(char) * 50);
        scanf("%s", words[cnt]);
        cnt++;
    }while((buffer = getchar()) != '\n' && buffer != '\r');

    char target[100];
    scanf("%s", target);
    int t_len = strlen(target);

    for(int i = 0; i < cnt; i++){
        if(strlen(words[i]) == t_len){
            int flag = 1;
            for(int j = 0; j < t_len; j++){
                if(words[i][j] != target[j]) flag = 0;
            }
            if(flag) ans++;
        }
    }

    printf("%d", ans);

    return 0;
}