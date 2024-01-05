#include<stdio.h>
int main(){
    double n1, n2, Ans;
    char a;
    scanf("%lf", &n1);
    while((a = getchar()) != '='){
        scanf("%lf", &n2);
        if(a == '+'){
            n1 += n2;
        }
        else if(a == '-'){
            n1 -= n2;
        }
        else if(a == '*'){
            n1 *= n2;
        }
        else if(a == '/'){
            if(n2 == 0){
                printf("You can't divide with zero!");
                return 0;
            }
            else{
                n1 /= n2;
            }
        }
        //printf("n1 = %lf\n", n1);
    }
    scanf("%lf", &Ans);
    int n11 = (int)(n1 * 100);
    int intAns = (int)(Ans * 100);
    if(n11 == intAns){
        printf("Correct!");
    }
    else{
        printf("BaBaBa, It's wrong.\n");
        printf("%.2lf", n1);
    }

}
