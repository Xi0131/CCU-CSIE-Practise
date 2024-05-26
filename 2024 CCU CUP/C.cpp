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
    ll n;
    cin >> n;
    while(n--){
        ll x;
        cin >> x;
        vector<int> ans;
        while(x != 0){
            ans.push_back(x % 128);
            x /= 128;
        }

        for(int i = ans.size()-1; i >= 0; i--){
            cout << (char)ans[i];
        }
        cout << '\n';
    }

	return 0;
}