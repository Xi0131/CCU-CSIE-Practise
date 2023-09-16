#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const int maxn = 200005;

void first(int i){
    if(i == 1) cout << "    *";
    else if(i == 4) cout << "*   *";
    else cout << "*****";
}

void second(int i){
    if(i == 0 || i == 4 || i == 8 || i == 9) cout << "*   *";
    else if(i == 1 || i == 2 || i == 3) cout << "    *";
    else if(i == 7) cout << "    *";
    else cout << "*    ";
}

void third(int i){
    if(i == 0) cout << "*   *";
    else if(i == 1 || i == 7) cout << "    *";
    else cout << "*****";
}

void forth(int i){
    if(i == 0 || i == 6 || i == 8) cout << "*   *";
    else if(i == 2) cout << "*    ";
    else cout << "    *";
}

void fifth(int i){
    if(i == 1 || i == 4 || i == 7 || i == 9) cout << "    *";
    else cout << "*****";
}

int main()
{
    int tmp;
    cin >> tmp;
    first(tmp/1000);
    cout << " ";
    first((tmp/100)%10);
    cout << " ";
    first((tmp/10)%10);
    cout << " ";
    first(tmp%10);
    cout << endl;
    second(tmp/1000);
    cout << " ";
    second((tmp/100)%10);
    cout << " ";
    second((tmp/10)%10);
    cout << " ";
    second(tmp%10);
    cout << endl;
    third(tmp/1000);
    cout << " ";
    third((tmp/100)%10);
    cout << " ";
    third((tmp/10)%10);
    cout << " ";
    third(tmp%10);
    cout << endl;
    forth(tmp/1000);
    cout << " ";
    forth((tmp/100)%10);
    cout << " ";
    forth((tmp/10)%10);
    cout << " ";
    forth(tmp%10);
    cout << endl;
    fifth(tmp/1000);
    cout << " ";
    fifth((tmp/100)%10);
    cout << " ";
    fifth((tmp/10)%10);
    cout << " ";
    fifth(tmp%10);
    cout << endl;

	return 0;
}