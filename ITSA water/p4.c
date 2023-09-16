#include<stdio.h>

int main(){

    int h1, m1, h2, m2;
    scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
    int min;
    if((m2 - m1) < 0){
        min = 60 + m2 - m1 + (h2 - (h1 + 1)) * 60;
        printf("%d\n", (60 + m2 - m1));
    }
    else if((m2 - m1) > 0) min = m2 - m1 + (h2 - h1) * 60;
    else min = (h2 - h1) * 60;

    int ans;
    if(min >= 240){
        ans += ((min - 240) % 30) * 60;
        min = 240;
    }
    if(min >= 120){
        printf("%d\n", (min % 30) * 40);
    }
    else{
        printf("%d\n", (min % 30) *30);
    }
    printf("%d\n", ans);

    return 0;
}