#include<bits/stdc++.h>
using namespace std;


int n,d;
int t[100100];
void solve(){
    cin >> n >> d;
    for(int i=0;i<n;i++){
        cin >> t[i];
    }
    sort(t,t+n);
    int sum=0;
    int ans=-1;
    for(int i=0;i<n;i++){
        if(i>0) t[i]+=t[i-1];
        if(sum+t[i]>d){
            ans=i;
            break;
        }
        sum+=t[i];
    }
    if(ans==-1){
        cout << n << ' ' << sum << endl;
    }
    else{
        cout << ans << ' ' << sum << endl;
    }
}
int main(){
    solve();
}