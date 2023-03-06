#include <stdio.h>
#include <string.h>

void goup(char* s, int lenS){
    for(int i = 0; i < lenS; i++){
        if(*(s + i) > 'Z' || *(s + i) < 'A'){
            *(s + i) -= 32;
        }
    }
}

void godown(char* s, int lenS){
    for(int i = 0; i < lenS; i++){
        if(*(s + i) > 'z' || *(s + i) < 'a'){
            *(s + i) += 32;
        }
    }
}

void wave(char* s, int lenS){
    for(int i = 1; i < lenS; i += 2){
        if(*(s + i) > 'z' || *(s + i) < 'a'){
            *(s + i) += 32;
        }
    }
    for(int i = 0; i < lenS; i += 2){
        if(*(s + i) > 'Z' || *(s + i) < 'A'){
            *(s + i) -= 32;
        }
    }
}

int main()
{
    char s[100001];
    fgets(s, 100001, stdin);
    int lenS = strlen(s) - 1;
    s[lenS] = '\0';
    int x;
    scanf("%d", &x);
    
    switch(x){
        case 1:
            goup(s, lenS);
            break;
        case 2:
            godown(s, lenS);
            break;
        case 3:
            wave(s, lenS);
            break;
    }
    
    printf("%s\n", s);

    return 0;
}

