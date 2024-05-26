#include<fstream>
#include<iostream>
#include<random>
#include<ctime>
using namespace std;

const int N = 10; //測資筆數

void open_input(ofstream &fout,int t_case){
    string dir_path = "../data/secret/";  //資料夾相對路徑
    string file_name = to_string(t_case)+".in"; //檔案名稱
    string real_path = dir_path + file_name; //開啟檔案位置
    fout.open(real_path , ios::out | ios::trunc); //覆寫
    if(!fout){
        cerr << "cannot open file " << real_path << endl;
        exit(1);
    }
}
void make_input(ofstream &fout, int t_case){
    /* 產生input資料 */
    
    /* 亂數引擎 */
    random_device rd;
    default_random_engine generator = default_random_engine(rd());
    uniform_int_distribution<int> unif(0,2147483647);
    
    //範測放前面
    if(t_case==1){
        fout << "3 3\n1 2 4\n2 3 6\n3 1 3" << endl;
    }
    else if(t_case==2){
        fout << "5 5\n1 2 3\n1 5 5\n1 4 9\n2 3 18\n3 5 7" << endl;
    }
    //放幾個比較能用肉眼看出答案的Random測資
    else if(t_case<=5){
        int n=unif(generator)%10+1;
        int d=unif(generator)%(n*(n-1)/2)+1;
        if(d < (n-1)) d += n-1;
        int cnt = 1;
        fout << n << ' ' << d << endl;
        vector<int> vec[n+1];
        for(int i=0;i<d;i++){
            int a, b;
            while(1){
                bool flag = 0;
                a = unif(generator)%n+1;
                b = unif(generator)%n+1;
                if(a == b) continue;
                for(int x : vec[a]){
                    if(x == b){
                        flag = 1;
                    }
                }
                if(flag) continue;
                break;
            }
            vec[a].push_back(b);
            vec[b].push_back(a);
            fout << a  << ' ' << b  << ' ' << cnt++ << '\n';
        }
        fout << endl;
    }
    // 放小的極端測資
    else if(t_case==6){
        int n=2;
        int d=1;
        fout << n << ' ' << d << endl;
        for(int i=0;i<d;i++){
            fout << 1  << ' ' << 2  << ' ' << 1;
        }
        fout << endl;
    }
    // 放大的極端測資
    else if(t_case==7){
        int n=50;
        int d = (n*(n-1)/2);
        // int d=unif(generator)%(n*(n-1)/2)+1;
        if(d < (n-1)) d += n-1;
        fout << n << ' ' << d << endl;
        int cnt = 1;
        bool flag = 0;
        for(int i=1;i<=n-1;i++){
            for(int j=2;j<=n;j++){
                fout << i << ' ' << j << ' ' << cnt++ << '\n';
                if(cnt > d){
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        fout << endl;
    }
    // 全隨機亂數
    else{
        int n=unif(generator)%50+1;
        int d=unif(generator)%(n*(n-1)/2)+1;
        if(d < (n-1)) d += n-1;
        int cnt = 1;
        fout << n << ' ' << d << endl;
        vector<int> vec[n+1];
        for(int i=0;i<d;i++){
            int a, b;
            while(1){
                bool flag = 0;
                a = unif(generator)%n+1;
                b = unif(generator)%n+1;
                if(a == b) continue;
                for(int x : vec[a]){
                    if(x == b){
                        flag = 1;
                    }
                }
                if(flag) continue;
                break;
            }
            vec[a].push_back(b);
            vec[b].push_back(a);
            fout << a  << ' ' << b  << ' ' << cnt++ << '\n';
        }
        fout << endl;
    }
}
void close_input(ofstream &fout,int t_case){
    fout.close();
}
int main(){
    for(int i=1;i<=N;i++){
        ofstream fout;
        open_input(fout,i); //要「寫入」輸入檔
        make_input(fout,i); //產生input
        close_input(fout,i); //關閉檔案
    }
}
