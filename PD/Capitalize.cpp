#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while(cin >> s){
        int flag = 1;
        for(auto c : s){
            if(isalpha(c)){
                if(flag) cout << (char)toupper(c);
                else cout << (char)tolower(c);
                flag = 0;
            }
        }
        cout << ' ';
    }
    return 0;
}