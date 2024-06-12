#include <iostream>
using namespace std;

int main(){

    int n;
    char ans[8];
    cin >> n;
    // scanf("%d", &n);
    if(n < 0){
        n = -n;
        for(int i = 7; i >= 0; i--){
            ans[i] = '0' + n % 2;
            n /= 2;
        }
        for(int i = 0; i < 8; i++){
            if(ans[i] == '0') ans[i] = '1';
            else ans[i] = '0';
        }
        int carry = 0;
        for(int i = 7; i >= 0; i--){
            if(ans[i] == '0' && carry == 0){
                ans[i] = '1';
                break;
            }
            else if(ans[i] == '0' && carry == 1){
                ans[i] = '1';
                break;
            }
            else{
                ans[i] = '0';
                carry = 1;
            }
        }
    }
    else{
        for(int i = 7; i >= 0; i--){
            ans[i] = '0' + n % 2;
            n /= 2;
        }
    }
    cout << ans << '\n';

    return 0;
}