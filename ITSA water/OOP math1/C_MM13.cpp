#include <iostream>
using namespace std;

int main(){

    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    // scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
    int min;
    min = (h2 - h1) * 60 + m2 - m1;

    int ans = 0;
    if(min >= 240){
        ans += ((min - 240) / 30) * 60;
        min = 240;
    }
    if(min >= 120){
        ans += ((min - 120) / 30) * 40;
        min = 120;
    }
    if(min >= 0){
        ans += (min / 30) * 30;
    }
    cout << ans << '\n';

    return 0;
}