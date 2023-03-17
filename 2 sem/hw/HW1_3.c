#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define watch(x) printf("%s is %c\n", (#x), (x))
#define debug printf("HI\n")

int main(){
    
    char *words[100];
    int method, n, str_len = 100, tgt_word;
    scanf("%d %d", &method, &n);
    for(int i = 0; i < n; i++){
        words[i] = (char*) malloc(sizeof(char) * 100);
        scanf("%s", words[i]);
        str_len = strlen(words[i]) < str_len ? strlen(words[i]) : str_len;
        tgt_word = i;
    }

    char common[100];
    int flag = 1, check = 1;
    if(method == 2) check = 0;

    for(int i = 0; i < str_len; i++){
        for(int j = 0; j < n; j++){
            if(!check){
                words[j][i] = tolower(words[j][i]);
                words[tgt_word][i] = tolower(words[tgt_word][i]);
            }
            if(words[tgt_word][i] != words[j][i]) flag = 0;
        }
        if(flag){
            common[i] = words[tgt_word][i];
            common[i+1] = '\0';
        }
        else{
            break;
        }
    }

    if(!strlen(common)) printf("No longest common prefix");
    else printf("%s", common);

    return 0;
}