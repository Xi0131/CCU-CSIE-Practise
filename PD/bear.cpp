#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));
    int max_area = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(graph[i][j] == 0){
                dp[i][j] = (i == 0) ? 1 : dp[i - 1][j] + 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    for(int i = 0; i < n; i++){
        stack<int> st;
        vector<int> left(m), right(m, m);

        for(int j = 0; j < m; j++){
            while(!st.empty() && dp[i][st.top()] >= dp[i][j]){
                right[st.top()] = j;
                st.pop();
            }
            left[j] = (st.empty()) ? -1 : st.top();
            st.push(j);
        }

        for(int j = 0; j < m; j++){
            cout << left[j] << ' ';
        } cout << '\n';

        for(int j = 0; j < m; j++){
            cout << right[j] << ' ';
        } cout << '\n';

        for(int j = 0; j < m; j++){
            max_area = max(max_area, dp[i][j] * (right[j] - left[j] - 1));
        }
    }

    cout << max_area << endl;
    return 0;
}
