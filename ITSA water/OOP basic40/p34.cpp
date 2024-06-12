#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    int n, m;
    while(cin.peek() != EOF){
        cin >> n >> m;
        // scanf("%d", &m);
        cout << fixed << setprecision(1);
        if(m == 1) cout << (float) (n - 80) * 0.7 << '\n';
        else cout << (float) (n - 70) * 0.6 << '\n';
        // if(m == 1) printf("%.1f\n", (float) (n - 80) * 0.7);
        // else printf("%.1f\n", (float) (n - 70) * 0.6);
    }

    return 0;
}