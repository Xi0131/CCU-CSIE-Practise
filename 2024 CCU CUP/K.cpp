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

bool cmp(const pii &a, const pii &b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

class comp{
public:
    bool operator() (pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b){
        return a.second > b.second; 
    }
};

bool vis[100005];

int main()
{
    ll n, m;
    cin >> n >> m;

    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, comp> q;
    
    for(int i = 0, a, b, c; i < m; i++){
        cin >> a >> b >> c;
        q.push({{a, b}, c});
    }

    vector<pii> ans;
    while(!q.empty()){
        pair<pair<int, int>, int> tmp = q.top();
        q.pop();
        if(!vis[tmp.first.first] || !vis[tmp.first.second]){
            ans.push_back({tmp.first.first, tmp.first.second});
            vis[tmp.first.first] = 1;
            vis[tmp.first.second] = 1;
        }
    }

    for(pii &x : ans){
        if(x.first > x.second) swap(x.first, x.second);
    }

    sort(ans.begin(), ans.end(), cmp);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }

	return 0;
}