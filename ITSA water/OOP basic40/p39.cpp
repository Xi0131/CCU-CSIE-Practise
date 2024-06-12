#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    // scanf("%d", &n);
    for(int i = 0, a, b, c; i < n; i++){
        cin >> a >> b >> c;
        // scanf("%d %d %d", &a, &b, &c);
        if(a >= 60 && b >= 60 && c >= 60) cout << ("P\n");
        else if((a + b + c) >= 220){
            if(a < 60 && b >= 60 && c >= 60) cout << ("P\n");
            else if(a >= 60 && b < 60 && c >= 60) cout << ("P\n");
            else if(a >= 60 && b >= 60 && c < 60) cout << ("P\n");
            else cout << ("F\n");
        }
        else if(a >= 80 || b >= 80 || c >= 80 || (a + b + c) < 220){
            if(a < 60 && b < 60 && c >= 80) cout << ("M\n");
            else if(a >= 80 && b < 60 && c < 60) cout << ("M\n");
            else if(a < 60 && b >= 80 && c < 60) cout << ("M\n");
            else if(a < 60 && b >= 60 && c >= 60) cout << ("M\n");
            else if(a >= 60 && b < 60 && c >= 60) cout << ("M\n");
            else if(a >= 60 && b >= 60 && c < 60) cout << ("M\n");
            else cout << ("F\n");
        }
    }

    return 0;
}