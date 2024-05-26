#include<fstream>
#include<iostream>
#include<algorithm>
#include<vector>
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

    long long n;
    finput >> n;
    while(n--){
        long long x;
        finput >> x;
        vector<int> ans;
        while(x != 0){
            ans.push_back(x % 128);
            x /= 128;
        }

        for(int i = ans.size()-1; i >= 0; i--){
            foutput << (char)ans[i];
        }
        foutput << '\n';
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
