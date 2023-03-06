#include<stdio.h>
#include<stdlib.h>
int main(){
    char t;
    int count[10] = {[0] = 1};
    while((t = getchar()) != EOF && t != '\n')
    {
        if(t != '0')
        {
            count[0] = 0;
            break;
        }
    }
    count[t-'0']++;
    while((t = getchar()) != EOF && t != '\n') count[t-'0']++;
    for(int i = '0'; i <= '9'; i++) printf("%c ", i);
    printf("\n");
    for(int i = '0'; i <= '9'; i++) printf("%d ", count[i-'0']);
    return 0;
}