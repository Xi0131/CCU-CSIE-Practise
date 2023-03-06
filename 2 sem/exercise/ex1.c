#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

void prt(char *a, char *b, int lenA, int lenB){
    lenA--; lenB--;
    printf("Reverse A: ");
    for(; lenA > -1; lenA--){
        printf("%c", *(a + lenA));
    }
    printf("\n");
    printf("Reverse B: ");
    for(; lenB > -1; lenB--){
        printf("%c", *(b + lenB));
    }
    printf("\n");
}

void len(int lenA, int lenB){
    printf("The length of A: %d\n", lenA);
    printf("The length of B: %d\n", lenB);
}

int occ(char *s, int len, char target){
    int cnt = 0;
    for(; len > -1; len--){
        if(*(s + len) == target){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    char a[101];
    char b[101];
    // printf("Input string A: ");
    fgets(a, 101, stdin);
    int lenA = strlen(a);
    lenA--;
    a[lenA] = '\0';
    // printf("Input string B: ");
    fgets(b, 101, stdin);
    int lenB = strlen(b);
    lenB--;
    b[lenB] = '\0';


    while(!feof(stdin)){
        int operand;
        scanf("%d", &operand);
        
        char c[202] = "\0";
        int comp = strncmp(a, b, MAX);
        switch(operand){
            case 1:
                prt(a, b, lenA, lenB);
                break;
            case 2:
                len(lenA, lenB);
                break;
            case 3:
                strcat(c, a);
                strcat(c, b);
                printf("The string after concatenates: %s\n", c);
                break;
            case 4:
                if(comp > 0){
                    printf("A is greater than B.\n");
                }
                else if(comp < 0){
                    printf("A is less than B.\n");
                }
                else{
                    printf("A is equal to B.\n");
                }
                break;
            case 5:
                printf("Whitespace of A: %d\n", occ(a, lenA, ' '));
                break;
            case 6:
                printf("Whitespace of B: %d\n", occ(b, lenB, ' '));
                break;
            default:
                printf("Error!\n");
                break;
        }
        scanf(" ");
    }

    return 0;
}