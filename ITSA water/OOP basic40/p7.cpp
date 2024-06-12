#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    for(int i = 0, a, b, c, d; i < n; i++){
        char op;
        cin >> op >> a >> b >> c >> d;
        if(op =='+'){
            cout << a + c << ' ' << b + d << '\n';
        }
        else if(op == '-'){
            cout << a - c << ' ' << b - d << '\n';
        }
        else{
            cout << a * c - (b * d) << ' ' << a * d + b * c << '\n';
        }
    }

    return 0;
}