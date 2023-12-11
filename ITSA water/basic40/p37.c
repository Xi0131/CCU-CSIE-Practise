#include <stdio.h>

int main(){

    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if(a == b && b == c && c == d) printf("WIN\n");
    else if(a != b && a != c && a != d && b != c && b != d && c != d) printf("R\n");
    else if(a != b && b == c && c == d) printf("R\n");
    else if(b != c && c == d && d == a) printf("R\n");
    else if(b != c && b == d && d == a) printf("R\n");
    else if(b != d && a == b && b == c) printf("R\n");
    else if(a == b){
        if(c != d) printf("%d\n", c + d);
        else printf("%d\n", (a + b) > (c + d) ? (a + b) : (c + d));
    }
    else if(b == c){
        if(a != d) printf("%d\n", a + d);
        else printf("%d\n", (b + c) > (a + d) ? (b + c) : (a + d));
    }
    else if(c == d){
        if(a != b) printf("%d\n", a + b);
        else printf("%d\n", (a + b) > (c + d) ? (a + b) : (c + d));
    }
    else if(d == a){
        if(b != c) printf("%d\n", b + c);
        else printf("%d\n", (b + c) > (a + d) ? (b + c) : (a + d));
    }
    else if(b == d){
        if(a != c) printf("%d\n", a + c);
        else printf("%d\n", (b + d) > (a + c) ? (b + d) : (a + c));
    }
    else if(a == c){
        if(b != d) printf("%d\n", b + d);
        else printf("%d\n", (b + d) > (a + c) ? (b + d) : (a + c));
    }

    return 0;
}