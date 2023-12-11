#include <stdio.h>  
  
int main(){  
  
    int x, y;
    while(scanf("%d", &x) != EOF){
        scanf("%d", &y);
        printf("%d\n", x + y); 
    };  
  
    return 0;  
}  