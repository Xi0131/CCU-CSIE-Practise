#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int name_existed(char *find_name, char **name_storage){
    int idx = 0;
    while(name_storage[idx] != 0){
        if(strcmp(find_name, name_storage[idx]) == 0){
            return idx;
        }
    }
    return -1;
}

int main(){

    int n;
    char banned_word[129];
    char **name_storage;
    char tmp_name[22];
    char msg[1024];
    int *is_banned;
    int name_cnt = 0;
    scanf("%d %s", &n, banned_word);

    for(int i = 0; i < n; i++){
        scanf("%s: %s", tmp_name, msg);
        int existed_idx = name_existed(tmp_name, name_storage);
        if(existed_idx != -1){
            if(is_banned[existed_idx] == 3){
                printf("%s is banned.", name_storage[existed_idx]);
            }
            else{
                
            }
        }
        else{
            name_storage[name_cnt] = (char*)realloc(name_storage, sizeof(name_storage) + sizeof(char) * strlen(tmp_name) + 1);
            name_storage[name_cnt][strlen(tmp_name)] = '\0';
            is_banned = (int*)realloc(is_banned, sizeof(is_banned) + sizeof(int));
            is_banned[name_cnt] = 0;
        }
    }

    return 0;
}