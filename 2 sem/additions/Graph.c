#include <stdio.h>
#include <stdlib.h>

#define watch_str(x) printf(#x " is %s\n", x)
#define watch_int(x) printf(#x " is %d\n", x)
#define debug printf("Debug line %d\n", __LINE__)

int main(){

    int n;
    scanf("%d", &n);
    int graph[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    int flag = 0;
    for(int i = 0; i < n; i++){
        int x;
        int num;
        scanf("%d", &x);
        int arr[n];
        for(int i = 0; i < n; i++) arr[i] = 0;
        while(scanf("%d", &num) != EOF){
            int space = getchar();
            arr[num] = 1;
            if(space == '\n') break;
        }

        for(int j = 0; j < n; j++){
            if(arr[j] != graph[i][j]){
                flag = 1;
                break;
            }
        }

        if(flag) break;
    }

    if(flag) printf("NO");
    else printf("YES");

    return 0;
}