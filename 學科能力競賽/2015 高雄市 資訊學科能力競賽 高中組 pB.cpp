#include <iostream>
using namespace std;

int main() 
{
    int h1, m1, h2, m2; cin >> h1 >> m1 >> h2 >> m2;

    int t1 = h1 * 60 + m1;
    int t2 = h2 * 60 + m2;

    int d = t2 - t1;
    if (d < 0) d += 1440; 

    cout << d / 60 << " " << d % 60;
}
