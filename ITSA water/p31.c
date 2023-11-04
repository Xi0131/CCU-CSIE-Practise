#include <stdio.h>

int main(){
    int arr[11];
    while(scanf("%d", &arr[0]) != EOF){
        for(int i = 1; i < 11; i++){
            scanf("%d", &arr[i]);
        }
        int flag = 0;
        for(int i = 0; i < 11; i++){
            int cnt = 0;
            int check = arr[i];
            for(int j = 0; j < 11; j++){
                if(arr[j] == check) cnt++;
                if(cnt == 6){
                    printf("%d\n", check);
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) printf("NO\n");
    }

    return 0;
}