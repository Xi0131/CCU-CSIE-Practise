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
    string s;
    cin >> s;
    int ans = 0;

    if(s.length() >= 12) ans += 10;
    else if(s.length() >= 8) ans += 5;

    for(char c : s)
        if(isalpha(c)){
            ans += 10;
            break;
        }

    for(char c : s)
        if(isdigit(c)){
            ans += 5;
            break;
        }

    for(char c : s)
        if(c == '!' || c == '@' || c == '#' || c == '%' || c == '^' || c == '&' || c == '*' || c == '_'){
            ans += 10;
            break;
        }

    int big = 0, small = 0;
    for(char c : s){
        if(c <= 'z' && c >= 'a'){
            small++;
        }
        else if(c <= 'Z' && c >= 'A'){
            big++;
        }
        if(big > 0 && small > 0){
            ans += 15;
            break;
        }
    }

    cout << ans;

	return 0;
}