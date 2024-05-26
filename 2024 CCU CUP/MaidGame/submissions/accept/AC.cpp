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
    int n;
    cin >> n;
    ll arr[n];
    bool flag = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){
            for(int k = j + 1; k < n; k++){
                if((arr[i] * arr[j] * arr[k]) % 9 == 0){
                    cout << arr[i] << ' ' << arr[j] << ' ' << arr[k] << '\n';
                    flag = 1;
                }
            }
        }
    }
    if(!flag) cout << "MOE MOE CHU\n";

	return 0;
}