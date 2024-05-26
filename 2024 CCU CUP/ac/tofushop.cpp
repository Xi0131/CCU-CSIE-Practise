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
    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i = 0, a, b; i < n; i++){
        cin >> a >> b;
        pq.push({a, b});
    }

    int pos = 0, ans = 0, stop = 0;
    priority_queue<pii> passed;
    while((pos + k) < m){
        // watch(k);
        int add = 0;
        int curr_max = pos + k;
        bool f = 0;
        while(!pq.empty()){
            pii x = pq.top();
            if(x.first <= curr_max){
                if(x.second > add){
                    watch(x.first);
                    add = max(add, x.second);
                    stop = x.first;
                    ans++;
                    f = true;
                }
                else{
                    debug;
                    passed.push({x.second, x.first});
                }
                pq.pop();
            }
            else{
                break;
            }
        }
        if(f){
            k = k - (stop - pos) + add;
            pos = stop;
        }
        else{
            if(!passed.empty()){
                debug;
                k += passed.top().first;
                ans++;
                passed.pop();
            }
            else{
                break;
            }
        }
    }

    cout << ans;

	return 0;
}