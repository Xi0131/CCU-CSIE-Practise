#include <stdio.h>

int main(){

    float f, comp, tmp;
    char opp;
    scanf("%f %c", &f, &opp);
    while(opp != '='){
        scanf("%f", &tmp);
        if(opp == '+'){
            f += tmp;
        }
        else if(opp == '-'){
            f -= tmp;
        }
        else if(opp == '*'){
            f *= tmp;
        }
        else if(opp == '/'){
            if(tmp == 0){
                printf("You can't divide with zero!\n");
                return 0;
            }
            else{
                f/= tmp;
            }
        }
        scanf("%c", &opp);
    }
    scanf("%f", &comp);
    // printf("%f %f\n", f, comp);
    if((f - comp) < 0.1 && (f - comp) >= 0){
        printf("Correct!\n");
    }
    else if((comp - f) < 0.1 && (comp - f) >= 0){
        printf("Correct!\n");
    }
    else{
        printf("BaBaBa, It's wrong.\n");
        printf("%.2f", f);
    }

    return 0;
}