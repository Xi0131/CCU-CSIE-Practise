#include <stdio.h>

size_t my_strlen (const char* str);
char* my_strcpy(char* dest, const char* source);
char* my_strcat(char* dest, const char* source);
int my_strcmp(const char* str1, const char* str2);

int main(){
    
    char *s;
    char *longest_str;
    int longest_length = 0;
    char *big_sentence;
    int cnt = 0;

    while(fgets(s, 101, stdin) != NULL){
        cnt++;
        longest_length = longest_length > my_strlen(s) ? longest_length : my_strlen(s);
        
        my_strcat(big_sentence, s);
    }

    printf("number of sentence: %d\n", cnt);
    printf("longest sentence: %s\n", longest_str);
    printf("longest length: %d\n", longest_length);
    printf("%s", big_sentence);

    return 0;
}

size_t my_strlen (const char* str){
    size_t len = 0;
    for(; *str != NULL; len++, str++);
    return len;
}

char* my_strcpy(char* dest, const char* source){
    dest = source;
    return dest;
}

char* my_strcat(char* dest, const char* source){
    for(; dest != NULL; dest++);
    dest = source;
    return dest;
}

int my_strcmp(const char* str1, const char* str2){
    if(my_strlen(str1) < my_strlen(str2)) return 0;
}