#include <iostream>
using namespace std;

int main(){

    int r, c;
    cin >> r >> c;
    int arr[c][r];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> arr[j][i];
        }
    }
    for(int i = 0; i < c; i++){
        for(int j = 0; j < r; j++){
            cout << ("%d", arr[i][j]);
            if(j != r - 1) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}