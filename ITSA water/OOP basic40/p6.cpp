#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    // scanf("%d", &n);
    if(n >= 3 && n <= 5) cout << ("Spring\n");
    if(n >= 6 && n <= 8) cout << ("Summer\n");
    if(n >= 9 && n <= 11) cout << ("Autumn\n");
    if((n >= 1 && n <= 2) || n == 12) cout << ("Winter\n");

    return 0;
}