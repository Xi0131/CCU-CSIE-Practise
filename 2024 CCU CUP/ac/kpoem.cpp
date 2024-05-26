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

bool vis[1000][1000];
int steps[1000][1000];

int main()
{
    int n, m, k;
    int s1, s2, e1, e2;
    cin >> n >> m >> k;
    int arr[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                s1 = i;
                s2 = j;
            }
            if(arr[i][j] == 3){
                e1 = i;
                e2 = j;
            }
        }
    }
    
    queue<pii> q;
    q.push({s1, s2});
    steps[s1][s2] = 0;
    while(!q.empty()){
        pii tmp = q.front();
        vis[tmp.first][tmp.second] = true;
        q.pop();
        if(steps[tmp.first][tmp.second] == k){
            continue;
        }
        if(tmp.first - 1 >= 0 && !vis[tmp.first - 1][tmp.second]){
            if(tmp.first - 1 == e1 && tmp.second == e2){
                cout << "YES";
                return 0;
            }
            else if(arr[tmp.first - 1][tmp.second] != 1){
                steps[tmp.first - 1][tmp.second] = steps[tmp.first][tmp.second] + 1;
                q.push({tmp.first - 1, tmp.second});
            }
        }
        if(tmp.second - 1 >= 0 && !vis[tmp.first][tmp.second - 1]){
            if(tmp.first == e1 && tmp.second - 1 == e2){
                cout << "YES";
                return 0;
            }
            else if(arr[tmp.first][tmp.second - 1] != 1){
                steps[tmp.first][tmp.second - 1] = steps[tmp.first][tmp.second] + 1;
                q.push({tmp.first, tmp.second - 1});
            }
        }
        if(tmp.first + 1 < n && !vis[tmp.first + 1][tmp.second]){
            if(tmp.first + 1 == e1 && tmp.second == e2){
                cout << "YES";
                return 0;
            }
            else if(arr[tmp.first + 1][tmp.second] != 1){
                steps[tmp.first + 1][tmp.second] = steps[tmp.first][tmp.second] + 1;
                q.push({tmp.first + 1, tmp.second});
            }
        }
        if(tmp.second + 1 < m && !vis[tmp.first][tmp.second + 1]){
            if(tmp.first == e1 && tmp.second + 1 == e2){
                cout << "YES";
                return 0;
            }
            else if(arr[tmp.first][tmp.second + 1] != 1){
                steps[tmp.first][tmp.second + 1] = steps[tmp.first][tmp.second] + 1;
                q.push({tmp.first, tmp.second + 1});
            }
        }
    }

    cout << "NO";

	return 0;
}