#include <iostream>
#include <vector>
using namespace std;

int i = 0;
ostream & funct(ostream &a) { a << (i++) ; return a;}
int main(){
    vector<int> vec = {1, 2, 3};
    vector<int>::iterator it = vec.begin();
    cout << *(it+1);
    return 0;
}