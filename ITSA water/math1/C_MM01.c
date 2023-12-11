#include <stdio.h>  
  
int main(){  
  
    int x, y, z;
    while(scanf("%d", &x) != EOF){
        scanf("%d %d", &y, &z);  
        printf("Trapezoid area:%.1lf\n", (x + y) * z * 0.5);  
    };  
  
    return 0;  
}  