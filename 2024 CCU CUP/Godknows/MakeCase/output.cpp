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
int bi(long long x){
    long long l = 1, r = 1<<30, mid;
    while(l <= r){
        mid = l + (r - l) / 2;
        long long tmp = mid * mid;
        if(tmp == x){
            return mid;
        }
        else if(tmp > x){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return 0;
}
void solve(ifstream &finput,ofstream &foutput, int t_case){
    /* 放完整解答Code */

    long long n, tmp;
    finput >> n;
    
    for(int i = 0; i < n; i++){
        finput >> tmp;
        int ans = bi(tmp);
        if(ans) foutput << ans << '\n';
        else foutput << "FOREVER SINGLE\n";
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
