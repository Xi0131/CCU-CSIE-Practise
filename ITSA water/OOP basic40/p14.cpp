#include <iostream>
#include <string>
using namespace std;

int main(){

    string str;
    cin >> str;
    int len = str.length();
    int n = len / 2;
    for(int i = 0; i < n; i++){
        if(str[i] != str[len - 1 - i]){
            cout << ("NO\n");
            return 0;
        }
    }
    cout << ("YES\n");

    return 0;
}