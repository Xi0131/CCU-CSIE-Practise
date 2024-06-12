#include <iostream>
#include <string>
using namespace std;

string a, b;

int main(){

    cin >> a >> b;
    int lenB = b.size(), lenA = a.size(), ans = 0;
    for(int i = 0; i <= lenB - lenA; i++){
        int flag = 0;
        for(int j = 0; j < lenA; j++){
            if(a[j] != b[i + j]) flag = 1;
        }
        if(!flag) ans++;
    }
    cout << ans << '\n';

    return 0;
}