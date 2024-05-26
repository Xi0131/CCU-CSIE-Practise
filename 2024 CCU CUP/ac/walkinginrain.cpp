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
    int h, m;
    cin >> h >> m;
    int tmp = h * 60 + m;
    int ref = 8 * 60 + 10;
    if(ref - tmp < 5) cout << "Fail";
    else if(ref - tmp < 15) cout << "Run";
    else cout << "Walk";

	return 0;
}