#include <stdio.h>
#include <stdlib.h>

size_t my_strlen (const char* str);
char* my_strcpy(char* dest, const char* source);
char* my_strcat(char* dest, const char* source);
int my_strcmp(const char* str1, const char* str2);

int main(){
    
    char *s = (char*) malloc(sizeof(char) * 101);
    char *longest_str = (char*) calloc(101, sizeof(char));
    int longest_length = 0;
    char *big_sentence = (char*) calloc(8193, sizeof(char));
    int cnt = 0;

    while(fgets(s, 101, stdin) != NULL){
        cnt++;
        int s_len = my_strlen(s);
        if(*(s + s_len - 1) == '\n') *(s + s_len - 1) = '\0';
        if(longest_length == s_len){
            if(my_strcmp(longest_str, s) < 0){
                my_strcpy(longest_str, s);
            }
        }
        else if(longest_length < s_len){
            my_strcpy(longest_str, s);
            longest_length = s_len;
        }
        my_strcat(big_sentence, s);
    }
    
    printf("number of sentence: %d\n", cnt);
    printf("longest sentence: %s\n", longest_str);
    printf("longest length: %d\n", longest_length);
    printf("%s\n", big_sentence);

    return 0;
}

size_t my_strlen(const char* str){
    size_t len = 0;
    for(; *(str + len) != '\0'; len++);
    return len;
}

char* my_strcpy(char* dest, const char* source){
    int i = 0;
    for(; *(source + i) != '\0'; i++) *(dest + i) = *(source + i);
    return dest;
}

char* my_strcat(char* dest, const char* source){
    int i = 0, j = 0;
    for(; *(dest + i) != '\0'; i++);
    for(; *(source + j) != '\0'; j++, i++) *(dest + i) = *(source + j);
    return dest;
}

int my_strcmp(const char* str1, const char* str2){
    int i = 0;
    for(; *(str1 + i) == *(str2 + i); i++);
    if(*(str1 + i) == '\0') return 0;
    else if(*(str1 + i) > *(str2 + i)) return 1;
    else if(*(str1 + i) < *(str2 + i)) return -1;
    return 0;
}