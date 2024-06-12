#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    
    double n;
    cin >> n;
    cout << showpoint << setprecision(4) << (float)(n*1.6) << '\n';

    return 0;
}