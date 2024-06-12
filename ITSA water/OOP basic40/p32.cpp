#include <iostream>
#include <ctype.h>
using namespace std;

int main(){
    string str;
    // cin >> str;
    // fgets(str, 101, stdin);
    getline(cin, str);
    int n;
    cin >> n;
    // scanf("%d", &n);
    n = n % 26;
    if(n == 0) cout << str;
    else{
        for(int i = 0; str[i] != '\0'; i++){
            if(isalpha(str[i])){
                if(isupper(str[i])){
                    if((str[i] + n) > 'Z') cout << (char)(str[i] - ('Z' - 'A' + 1) + n);
                    else cout << (char)(str[i] + n);
                }
                else{
                    if((str[i] + n) > 'z'){
                        cout << (char)(str[i] - ('z' - 'a' + 1) + n);
                    }
                    else cout << (char)(str[i] + n);
                }                
            }
            else if(isdigit(str[i])){
                if((str[i] + n) > '9') cout << (char)(str[i] - ('9' - '0' + 1) + n);
                else cout << (char)(str[i] + n);
            }
            else cout << (char)(str[i]);
        }
    }
    cout << '\n';

    return 0;
}