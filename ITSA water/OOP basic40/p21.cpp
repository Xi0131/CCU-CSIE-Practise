#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    float arr[10];
    for(int i = 0; i < 10; i++){
        cin >> arr[i];
        // scanf("%f", &arr[i]);
    }
    float max = arr[0];
    float min = arr[0];

    for(int i = 1; i < 10; i++){
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }

    cout << fixed;
    cout << setprecision(2);
    cout << "maximum:" << max << '\n';
    cout << "minimum:" << min << '\n';

    return 0;
}