#include <iostream>
#include <math.h>
using namespace std;

int main(){

    double x, y;
    cin >> x >> y;
    // scanf("%lf %lf", &x, &y);
    if(sqrt(x*x + y*y) > 200) cout << ("outside\n");
    else cout << ("inside\n");

    return 0;
}