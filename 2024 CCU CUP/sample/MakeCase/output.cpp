#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;

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
void solve(ifstream &finput,ofstream &foutput, int t_case){
    /* 放完整解答Code */

    finput >> n >> d;
    for(int i=0;i<n;i++){
        finput >> t[i];
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
        foutput << n << ' ' << sum << endl;
    }
    else{
        foutput << ans << ' ' << sum << endl;
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
