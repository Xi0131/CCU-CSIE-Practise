#include <stdio.h>

int main(){
    int arr[11];
    char n = '\0';
    while(n != EOF){
        int test;
        for(int k = 0; k < 11; k++){
            test = scanf("%d", &arr[k]);
            n = getchar();
            if(n == '\n'){
                int flag = 0;
                for(int i = 0; i <= k; i++){
                    int cnt = 0;
                    int check = arr[i];
                    for(int j = 0; j <= k; j++){
                        if(arr[j] == check) cnt++;
                        if(cnt >= k/2){
                            printf("%d\n", check);
                            flag = 1;
                            break;
                        }
                    }
                    if(flag) break;
                }
                if(!flag) printf("NO\n");
                break;
            }
            if(n == EOF) break;
        }
    }

    return 0;
}