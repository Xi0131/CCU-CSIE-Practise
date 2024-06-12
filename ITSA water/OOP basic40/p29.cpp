#include <iostream>
using namespace std;

int main(){

    string c;
    string alp = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X', 'Y', 'W', 'Z', 'I', 'O'};
    cin >> c;
    // scanf("%s", c);
    char d;
    for(int i = 0; i < 26; i++){
        if(c[0] == alp[i]){
            d = 10 + i;
            break;
        }
    }
    int a, b;
    a = (int) (d / 10);
    b = (int) (d % 10);
    int ans = (int) (a + (9 * b) + (8 * (c[1] - '0')) + (7 * (c[2] - '0')) + (6 * (c[3] - '0')) + (5 * (c[4] - '0')) + (4 * (c[5] - '0')) + (3 * (c[6] - '0')) + (2 * (c[7] - '0')) + c[8] - '0' + c[9] - '0');
    if(ans % 10 == 0) cout << ("CORRECT!!!\n");
    else cout << ("WRONG!!!\n");

    return 0;
}