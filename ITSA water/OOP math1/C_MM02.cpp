#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    float x, y;
    cin >> x >> y;
    // scanf("%f %f", &x, &y);
    cout << fixed << showpoint << setprecision(1);
    cout << (double)(0.5 * x * y) << '\n';
    // printf("%.1f\n", 0.5 * x * y);

    return 0;
}