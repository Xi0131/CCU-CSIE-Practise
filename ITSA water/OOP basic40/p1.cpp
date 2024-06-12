#include <iostream>
using namespace std;

void first(int i){
    if(i == 1) cout << ("    *");
    else if(i == 4) cout << ("*   *");
    else cout << ("*****");
}

void second(int i){
    if(i == 0 || i == 4 || i == 8 || i == 9) cout << ("*   *");
    else if(i == 1 || i == 2 || i == 3) cout << ("    *");
    else if(i == 7) cout << ("    *");
    else cout << ("*    ");
}

void third(int i){
    if(i == 0) cout << ("*   *");
    else if(i == 1 || i == 7) cout << ("    *");
    else cout << ("*****");
}

void forth(int i){
    if(i == 0 || i == 6 || i == 8) cout << ("*   *");
    else if(i == 2) cout << ("*    ");
    else cout << ("    *");
}

void fifth(int i){
    if(i == 1 || i == 4 || i == 7 || i == 9) cout << ("    *");
    else cout << ("*****");
}

int main()
{
    int tmp;
    cin >> tmp;
    first(tmp/1000);
    cout << (" ");
    first((tmp/100)%10);
    cout << (" ");
    first((tmp/10)%10);
    cout << (" ");
    first(tmp%10);
    cout << ("\n");
    second(tmp/1000);
    cout << (" ");
    second((tmp/100)%10);
    cout << (" ");
    second((tmp/10)%10);
    cout << (" ");
    second(tmp%10);
    cout << ("\n");
    third(tmp/1000);
    cout << (" ");
    third((tmp/100)%10);
    cout << (" ");
    third((tmp/10)%10);
    cout << (" ");
    third(tmp%10);
    cout << ("\n");
    forth(tmp/1000);
    cout << (" ");
    forth((tmp/100)%10);
    cout << (" ");
    forth((tmp/10)%10);
    cout << (" ");
    forth(tmp%10);
    cout << ("\n");
    fifth(tmp/1000);
    cout << (" ");
    fifth((tmp/100)%10);
    cout << (" ");
    fifth((tmp/10)%10);
    cout << (" ");
    fifth(tmp%10);
    cout << ("\n");

	return 0;
}