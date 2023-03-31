#include <stdio.h>

int main(){

    int quantity, f_per_hour;
    scanf("%d %d", &quantity, &f_per_hour);
    int time[quantity];
    for(int i = 0; i < quantity; i++) scanf("%d", &time[quantity-1]);

    for(int i = 0; i < quantity; i++){
        for(int j = 0; j < quantity - 1 - i; j++){
            if(time[j] > time[j + 1]){
                int t = time[j];
                time[j] = time[j + 1];
                time[j + 1] = t;
            }
        }
    }

    return 0;
}