#include <iostream>
using namespace std;

int main()
{
    int i = 1;
    int j = 10;
    
    while(!((i%j)==0))
    {
        i++;
    }

    cout << i;

    return 0;
}
