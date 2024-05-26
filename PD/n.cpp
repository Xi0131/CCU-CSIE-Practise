#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
#define MAX 1000
int n, rec, minn;
vector <int> arr;
vector <int> graph[MAX + 10];

void DFS(int level, int times){
    if(level == n){
        minn = min(minn, times);
        return;
    }
    for(auto x : graph[level]){
        DFS(x, times + 1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> rec;
        arr.push_back(rec);
        for(int j = 1; (j <= rec); j++){
            if(j + i >= n){
                graph[i].push_back(n);
                break;
            }
            graph[i].push_back(j + i);
        }
    }
    minn = MAX + 1;
    DFS(0, 0);
    cout << minn << endl;
    return 0;
}