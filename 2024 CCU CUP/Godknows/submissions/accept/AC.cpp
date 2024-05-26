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

int bi(ll x){
    ll l = 1, r = INF32, mid;
    while(l <= r){
        mid = l + (r - l) / 2;
        ll tmp = mid * mid;
        if(tmp == x){
            return mid;
        }
        else if(tmp > x){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return 0;
}

int main()
{
    ll n, tmp;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> tmp;
        int ans = bi(tmp);
        if(ans) cout << ans << '\n';
        else cout << "FOREVER SINGLE\n";
    }

	return 0;
}