#include <iostream>
using namespace std;

int main(){
    int a, b, t;
    cin >> a >> b;
    // scanf("%d %d", &a, &b);
    while(b != 0){
        t = b;
        b = a % b;
        a = t;
    }
    cout << a << '\n';
}