#include <iostream>
#include <vector>
using namespace std;

int main() 
{

    long long int f[50];
    f[0] = 1;
    f[1] = 2;
    for (int i = 2; i < 50; i++)
    {
    	f[i] = f[i - 1] + f[i - 2];
    }

    int T;
    cin >> T;
    while (T--) 
    {
        long long k;
        cin >> k;

        cout << k << " = ";

        
        int idx = 49;
        while (idx > 0 && f[idx] > k) idx--;

        long long cur = k;
        for (int i = idx; i >= 0; i--) {
            if (f[i] <= cur) {
                cout << '1';
                cur -= f[i];
            } else {
                cout << '0';
            }
        }

        cout << " (fib)\n";
    }

    return 0;
}
