#include <stdio.h>

void first(int i){
    if(i == 1) printf("    *");
    else if(i == 4) printf("*   *");
    else printf("*****");
}

void second(int i){
    if(i == 0 || i == 4 || i == 8 || i == 9) printf("*   *");
    else if(i == 1 || i == 2 || i == 3) printf("    *");
    else if(i == 7) printf("    *");
    else printf("*    ");
}

void third(int i){
    if(i == 0) printf("*   *");
    else if(i == 1 || i == 7) printf("    *");
    else printf("*****");
}

void forth(int i){
    if(i == 0 || i == 6 || i == 8) printf("*   *");
    else if(i == 2) printf("*    ");
    else printf("    *");
}

void fifth(int i){
    if(i == 1 || i == 4 || i == 7 || i == 9) printf("    *");
    else printf("*****");
}

int main()
{
    int tmp;
    scanf("%d", &tmp);
    first(tmp/1000);
    printf(" ");
    first((tmp/100)%10);
    printf(" ");
    first((tmp/10)%10);
    printf(" ");
    first(tmp%10);
    printf("\n");
    second(tmp/1000);
    printf(" ");
    second((tmp/100)%10);
    printf(" ");
    second((tmp/10)%10);
    printf(" ");
    second(tmp%10);
    printf("\n");
    third(tmp/1000);
    printf(" ");
    third((tmp/100)%10);
    printf(" ");
    third((tmp/10)%10);
    printf(" ");
    third(tmp%10);
    printf("\n");
    forth(tmp/1000);
    printf(" ");
    forth((tmp/100)%10);
    printf(" ");
    forth((tmp/10)%10);
    printf(" ");
    forth(tmp%10);
    printf("\n");
    fifth(tmp/1000);
    printf(" ");
    fifth((tmp/100)%10);
    printf(" ");
    fifth((tmp/10)%10);
    printf(" ");
    fifth(tmp%10);
    printf("\n");

	return 0;
}