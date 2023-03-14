#include <stdio.h>
#include <string.h>

int main(){
    char* sentence[100001];
    char temp[100];
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
    for(int i = 0; i <= iterator; i++)
    printf("%s %d \n", sentence[i], strlen(sentence[i]));
    printf("%d", sizeof(sentence));

    return 0;
}