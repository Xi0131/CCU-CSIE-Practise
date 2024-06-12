#include <iostream>
using namespace std;

int main(){

    int num[10];
    for(int i = 0; i < 10; i++){
        // cout << "de\n";
        char c, d;
        cin >> c;
        // scanf("%c", &c);
        if(c == 'X') num[i] = 10;
        else num[i] = c - '0';
        // getchar();
        // cin >> d;
    }
    
    for(int i = 1; i < 10; i++){
        num[i] += num[i-1];
    }

    for(int i = 1; i < 10; i++){
        num[i] += num[i-1];
    }

    if(num[9] % 11 == 0) cout << ("YES\n");
    else cout << ("NO\n");

    return 0;
}