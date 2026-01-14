#include <iostream>
using namespace std;

int cycleLen(long long n) {
    if (n == 1) return 1;               
    if (n % 2 == 1) return 1 + cycleLen(3 * n + 1);
    else return 1 + cycleLen(n / 2);
}

int main() 
{

    long long i, j;
    while (cin >> i >> j) 
    {
        long long a = min(i, j), b = max(i, j);
        int mx = 0;
        for (long long x = a; x <= b; x++) {
            mx = max(mx, cycleLen(x));
        }
        cout << i << " " << j << " " << mx << "\n";
    }
    return 0;
}
