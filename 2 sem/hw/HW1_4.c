#include <stdio.h>

int main(){
    char* sentence[100001];
    char* temp;
    char space;
    int iterator = 0;
    do{
        scanf("%s", temp);
            printf("%s ", temp);
        sentence[iterator] = temp;
        space = getchar();
        iterator++;
        if(space == ' ');
    }while(space != '\n');

    char target[100];
    scanf("%s", target);
    printf("%s", target);


    return 0;
}