#include <stdio.h>

#define watch_int(x) printf(#x " is %d\n", x)
#define watch_string(x) printf(#x " is %s\n", x)
#define debug printf("Debug line %d\n", __LINE__)

int main(){

    int arr[1000];
    int x;
    int idx = 0;
    int flag = 0;
    scanf("%d", &x);
    if(x == 1){
        printf("1");
        flag = 1;
    }
    while(x > 1){
        for(int i = 9; i >= 2; i--){
            if(x % i == 0){
                // watch_int(x);
                // watch_int(i);
                x /= i;
                arr[idx] = i;
                idx++;
                break;
            }
            else if(i == 2){
                printf("-1");
                flag = 1;
                break;
            }
        }
        if(flag){
            break;
        }
    }

    if(!flag){
        for(int i = idx - 1; i >= 0; i--){
            printf("%d", arr[i]);
        }
    }

    return 0;
}