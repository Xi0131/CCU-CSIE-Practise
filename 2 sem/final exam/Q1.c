#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        if(x > 2*y || y > 2*x){
            printf("NO\n");
        }
        else if((x + y) % 3 == 0){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }

    return 0;
}