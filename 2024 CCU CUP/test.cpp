#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << __LINE__ << endl

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
    while(n--){
        string s;
        cin >> s;
        ll ans = s[0];
        for(int i = 1; i < s.size(); i++){
            ans = ans * 128 + (int)s[i];
        }
        cout << ans << '\n';
    }

	return 0;
}