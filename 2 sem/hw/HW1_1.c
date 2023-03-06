#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    while(x > 1){
        int t;
        for(int i = 2; i <= x; i++){
            if(x % i == 0){
                t = i;
                x /= i;
                break;
            }
        }
        printf("%d ", t);
    }

    return 0;
}
