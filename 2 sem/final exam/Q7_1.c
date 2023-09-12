#include <stdio.h>
#include <stdlib.h>

typedef int bool;

char *recorded_name[22];
int cnt_name;

int my_strcmp(char *a, char *b){
    int result;
    for(int i = 0, j = 0; *(a + i) != '\0' && *(b + i) != '\0'; i++, j++){
        if(result = *(a + i) - *(b + i) != 0){
            return result;
        }
    }
    return result;
}

bool check_recorded(char *tgt){
    int result;
    for(int i = 0; recorded_name[i] != NULL; i++){
        if(my_strcmp(tgt, recorded_name[i]) == 0){
            return 1;
        }
    }
    return 0;
}

int main(){

    int n;
    char banned_word[129];
    char name[22];
    char msg[1024];
    int *is_banned;
    scanf("%d %s", &n, banned_word);

    char word[100];
    for(int i = 0; i < n; i++){

        scanf("%s", name);
        // if not exist, add name
        if(!check_recorded(name)){
            recorded_name[cnt_name++] = (char *)malloc(sizeof(char) * 22);
            is_banned = realloc(is_banned, sizeof(is_banned) + sizeof(int));
        }
        getchar();

        int enter;
        do{
            scanf("%s", word);
            if(strcmp(word, banned_word) == 0){

            }
        }while(enter = getchar() != '\n');
    }
    

    return 0;
}