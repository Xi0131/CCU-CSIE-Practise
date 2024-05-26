#include<iostream>
using namespace std;

#define floor(x, b) x>=b ? 0:1

int main(){
    int a = 3;
    int b = floor(a&0x0f, 0x07);
    int c = floor((a&0x0f), 0x07);
    cout << b << ' ' << c;    
    return 0;
}