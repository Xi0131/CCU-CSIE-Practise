#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi " << __LINE__ << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;


int main()
{
    int n, m;
    cin >> n >> m;
    ll arr[n+1][m+1];
    for(int i = 0; i <= m; i++){
        arr[0][i] = 0;
    }
    for(int i = 0; i <= n; i++){
        arr[i][0] = 0;
    }

    arr[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i != 1 || j != 1){
                arr[i][j] = arr[i-1][j] + arr[i][j-1];
            }
        }
    }

    cout << arr[n][m];

	return 0;
}