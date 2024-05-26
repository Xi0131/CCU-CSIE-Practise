#include<fstream>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 10; //測資筆數


int n,d;
int t[100100];

void open_file(ifstream &finput,ofstream &foutput,int t_case){
    string dir_path = "../data/secret/";  //資料夾相對路徑

    string input_file_name = to_string(t_case)+".in"; //檔案名稱
    string output_file_name = to_string(t_case)+".ans";
    
    string input_path = dir_path + input_file_name; //開啟檔案位置
    string output_path = dir_path + output_file_name;
    
    finput.open(input_path , ios::in); 
    foutput.open(output_path , ios::out | ios::trunc);
    
    if(!finput){
        cerr << "cannot open input file " << input_path << endl;
        exit(1);
    }
    if(!foutput){
        cerr << "cannot open output file " << output_path << endl;
        exit(1);
    }
}
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
void solve(ifstream &finput,ofstream &foutput, int t_case){
    /* 放完整解答Code */

    ll n, m;
    finput >> n >> m;
    vector<pii> vec[n+1];
    for(int i = 0, a, b, c; i < m; i++){
        finput >> a >> b >> c;
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
        foutput << x.first << ' ' << x.second << '\n';
    }
}
void close_file(ifstream &finput,ofstream &foutput,int t_case){
    finput.close();
    foutput.close();
}
int main(){
    for(int i=1;i<=N;i++){
        ifstream finput;
        ofstream foutput;
        open_file(finput,foutput,i); //要讀入輸入檔，寫入輸出檔
        solve(finput,foutput,i); //放解答 Code
        close_file(finput,foutput,i); //關閉檔案
    }
}
