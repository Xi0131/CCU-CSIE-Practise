#include <iostream>
using namespace std;

int main(){

    int n;
    long long int ans = 0;
    cin >> n;
    // scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        if(i % 3 == 0) ans += i;
    }
    cout << ans << '\n';

    return 0;
}