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
    vector<pii> vec[n+1];
    for(int i = 0, a, b, c; i < m; i++){
        cin >> a >> b >> c;
        vec[a].push_back(make_pair(b, c));
        vec[b].push_back(make_pair(a, c));
    }

    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, comp> pq;
    for(pii x : vec[1]) pq.push({{1, x.first}, x.second});
    vector<pii> ans;
    while(!pq.empty()){
        pair<pair<int, int>, int> tmp = pq.top();
        pq.pop();

        if(!vis[tmp.first.first] || !vis[tmp.first.second]){
            ans.push_back({tmp.first.first, tmp.first.second});
            vis[tmp.first.first] = 1;
            vis[tmp.first.second] = 1;
            
            for(pii x : vec[tmp.first.second]){
                if(!vis[x.first])
                pq.push({{tmp.first.second, x.first}, x.second});
            }
        }
    }

    for(pii &x : ans) if(x.first > x.second) swap(x.first, x.second);
    sort(ans.begin(), ans.end());

    for(pii x : ans){
        cout << x.first << ' ' << x.second << '\n';
    }

	return 0;
}