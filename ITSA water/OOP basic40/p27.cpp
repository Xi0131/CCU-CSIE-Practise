#include <iostream>
#include <string>
using namespace std;

int main(){
    string ref;
    cin >> ref;
    // scanf("%s", ref);
    while(1){
        int a = 0, b = 0;
        string tmp, zero = "0000";
        // scanf("%s", tmp);
        cin >> tmp;
        if(tmp == zero) break;
        for(int i = 0; i < 4; i++){
            if(ref[i] == tmp[i]) a++;
        }
        for(int i = 0; i < 4; i++){
            if(ref[i] != tmp[i]){
                for(int j = 0; j < 4; j++){
                    if(ref[i] == tmp[j]){
                        b++;
                        tmp[j] = 'A';
                        break;
                    }
                }
            }
        }
        // cout << ("%dA%dB\n", a, b);
        cout << a << 'A' << b << 'B' << '\n';
    }

    return 0;
}