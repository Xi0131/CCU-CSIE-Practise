#include<stdio.h>
#include<math.h>

int main(){

    double x, y;
    scanf("%lf %lf", &x, &y);
    if(sqrt(x*x + y*y) > 200) printf("outside\n");
    else printf("inside\n");

    return 0;
}