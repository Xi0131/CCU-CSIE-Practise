#include <iostream>
using namespace std;

int main(){

    int n, a, b, c, x, y, z;
    char ch;
    cin >> n >> ch >> a >> ch >> b >> ch >> c;
    // scanf("%d,%d,%d,%d", &n, &a, &b, &c);
    if(a * 15 + b * 20 + c * 30 > n) cout << ("0\n");
    else{
        n -= a * 15 + b * 20 + c * 30;
        z = n / 50;
        n %= 50;
        y = n / 5;
        n %= 5;
        x = n;
        // cout << ("%d,%d,%d\n", x, y, z);
        cout << x << ',' << y << ',' << z << '\n';
    }

    return 0;
}