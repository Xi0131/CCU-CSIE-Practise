#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char str[100] = {};
    fgets(str, sizeof(str), stdin);
    str[strlen(str)-1] = '\0';
    int flag = 0;
    for(int i = 0; i < 100; i++){
        if(str[i] == '\0') break;
        else if(str[i] != '0' && str[i] != '1'){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        for(int i = 0; i < 100; i++){
            if(str[i] == '\0') break;
            if(str[i] <= 'Z' && str[i] >= 'A'){
                printf("%c", str[i] - 'A' + 'a');
            }
            else if(str[i] <= 'z' && str[i] >= 'a'){
                printf("%c", str[i]);
            }
            else if(str[i] <= '9' && str[i] >= '0'){
                printf("%c", str[i]);
            }
            else{
                printf("%%%d", (int)str[i]);
            }
        }
        printf(" is not a binary number");
    }
    else{
        printf("%s is a binary number, ", str);
        unsigned long long tmp = 0;
        int len = strlen(str);
        unsigned long long two = 2;
        for(int i = len - 2; i >= 0; i--, two *= 2){
            if(str[i] == '1') tmp += two;
        }
        if(str[len-1] == '1') tmp++;
        printf("%llu", tmp);
    }
    return 0;
}