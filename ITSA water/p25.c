#include <stdio.h>
char string[32];
int main(){
    int n, ans = 0;
    char c;
    scanf("%d ", &n);

    while(scanf("%c", &c) != EOF){
        if (c == '\n'){
            printf("%d \n", ans);
            ans = 0;
        }
        else ans += c;
    }

    /*
    getchar();
    for(int i = 0; i < n; i++){
        fgets(string, 32, stdin);
        int ans = 0;
        for(int j = 0; j < 32; j++){
            if(string[j] == '\n') break;
            ans += (int) string[j];
        }
        printf("%d\n", ans);
        for(int j = 0; j < 32; j++){
            string[j] = 0;
        }
    }*/
    return 0;
}