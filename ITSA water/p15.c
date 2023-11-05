#include <stdio.h>
#include <string.h>
#include <ctype.h>

int arr[26], cnt;

int main(){

    char str[101];
    fgets(str, 101, stdin);
    int len = strlen(str);
    if(!isspace(str[len - 1])) str[len++] = ' ';
    for(int i = 0; i < len; i++){
        if(isalpha(str[i])){
            str[i] = tolower(str[i]);
            arr[str[i] - 'a']++;
        }
        if(isspace(str[i])) cnt++;
    }

    printf("%d\n", cnt);
    for(int i = 0; i < 26; i++){
        if(arr[i] != 0) printf("%c : %d\n", i + 'a', arr[i]);
    }

    return 0;
}