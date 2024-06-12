#include <iostream>
using namespace std;

int main(){

    int a, b, c, d;
    // scanf("%d%d%d%d", &a, &b, &c, &d);
    cin >> a >> b >> c >> d;
    if(a == b && b == c && c == d) cout << ("WIN\n");
    else if(a != b && a != c && a != d && b != c && b != d && c != d) cout << ("R\n");
    else if(a != b && b == c && c == d) cout << ("R\n");
    else if(b != c && c == d && d == a) cout << ("R\n");
    else if(b != c && b == d && d == a) cout << ("R\n");
    else if(b != d && a == b && b == c) cout << ("R\n");
    else if(a == b){
        if(c != d) cout << c + d << '\n';
        else cout << ((a + b) > (c + d) ? (a + b) : (c + d)) << '\n';
        // if(c != d) printf("%d\n", c + d);
        // else printf("%d\n", (a + b) > (c + d) ? (a + b) : (c + d));
    }
    else if(b == c){
        if(c != d) cout << a + d << '\n';
        else cout << ((b + c) > (a + d) ? (b + c) : (a + d)) << '\n';
        // if(a != d) printf("%d\n", a + d);
        // else printf("%d\n", (b + c) > (a + d) ? (b + c) : (a + d));
    }
    else if(c == d){
        if(c != d) cout << a + b << '\n';
        else cout << ((a + b) > (c + d) ? (a + b) : (c + d)) << '\n';
        // if(a != b) printf("%d\n", a + b);
        // else printf("%d\n", (a + b) > (c + d) ? (a + b) : (c + d));
    }
    else if(d == a){
        if(c != d) cout << b + c << '\n';
        else cout << ((b + c) > (a + d) ? (b + c) : (a + d)) << '\n';
        // if(b != c) printf("%d\n", b + c);
        // else printf("%d\n", (b + c) > (a + d) ? (b + c) : (a + d));
    }
    else if(b == d){
        if(c != d) cout << a + c << '\n';
        else cout << ((b + d) > (a + c) ? (b + d) : (a + c)) << '\n';
        // if(a != c) printf("%d\n", a + c);
        // else printf("%d\n", (b + d) > (a + c) ? (b + d) : (a + c));
    }
    else if(a == c){
        if(c != d) cout << b + d << '\n';
        else cout << ((b + d) > (a + c) ? (b + d) : (a + c)) << '\n';
        // if(b != d) printf("%d\n", b + d);
        // else printf("%d\n", (b + d) > (a + c) ? (b + d) : (a + c));
    }

    return 0;
}