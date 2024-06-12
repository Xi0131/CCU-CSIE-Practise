#include <iostream>
using namespace std;

int main(){

    int m, d;
    cin >> m >> d;
    // scanf("%d %d", &m, &d);
    if((m == 1 && d >= 21) || (m == 2 && d <= 18)) cout << ("Aquarius\n");
    if((m == 2 && d >= 19) || (m == 3 && d <= 20)) cout << ("Pisces\n");
    if((m == 3 && d >= 21) || (m == 4 && d <= 20)) cout << ("Aries\n");
    if((m == 4 && d >= 21) || (m == 5 && d <= 21)) cout << ("Taurus\n");
    if((m == 5 && d >= 22) || (m == 6 && d <= 21)) cout << ("Gemini\n");
    if((m == 6 && d >= 22) || (m == 7 && d <= 22)) cout << ("Cancer\n");
    if((m == 7 && d >= 23) || (m == 8 && d <= 23)) cout << ("Leo\n");
    if((m == 8 && d >= 24) || (m == 9 && d <= 23)) cout << ("Virgo\n");
    if((m == 9 && d >= 24) || (m == 10 && d <= 23)) cout << ("Libra\n");
    if((m == 10 && d >= 24) || (m == 11 && d <= 22)) cout << ("Scorpio\n");
    if((m == 11 && d >= 23) || (m == 12 && d <= 21)) cout << ("Sagittarius\n");
    if((m == 12 && d >= 22) || (m == 1 && d <= 20)) cout << ("Capricorn\n");

    return 0;
}