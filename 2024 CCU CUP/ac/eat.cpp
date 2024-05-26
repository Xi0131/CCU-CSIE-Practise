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
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];

    sort(vec.rbegin(), vec.rend());

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(vec[i] < k){
            for(int j = 0; j < n; j++){
                if(vec[i] + vec[j] < k){
                    ans = max(ans, vec[i] + vec[j]);
                    break;
                }
            }
        }
    }

    cout << ans;

	return 0;
}