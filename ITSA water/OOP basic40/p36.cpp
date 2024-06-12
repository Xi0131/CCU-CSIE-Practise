#include <iostream>
using namespace std;

int main(){

    int n, flag = 0;
    cin >> n;
    // scanf("%d", &n);
    if(n % 400 == 0) flag = 0;
    else if(n % 100 == 0) flag = 1;
    else if(n % 4 == 0) flag = 0;
    else flag = 1;
    if(flag) cout << ("Common Year\n");
    else cout << ("Bissextile Year\n");

    return 0;
}