#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    float x;
    cin >> x;
    // scanf("%f %f", &x, &y);
    cout << fixed << showpoint << setprecision(1);
    cout << ((x) * 9 / 5) + 32 << '\n';
    // cout << (double)(0.5 * x * y) << '\n';

    return 0;
}