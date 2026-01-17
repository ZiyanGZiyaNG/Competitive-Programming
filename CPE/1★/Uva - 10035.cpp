#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() 
{

    string a, b;
    while (cin >> a >> b) 
    {
        if (a == "0" && b == "0") break;

        int i = (int)a.size() - 1;
        int j = (int)b.size() - 1;
        int carry = 0;
        int cnt = 0;

        while (i >= 0 || j >= 0) 
        {
            int da = (i >= 0) ? (a[i] - '0') : 0;
            int db = (j >= 0) ? (b[j] - '0') : 0;
            int s = da + db + carry;
            if (s >= 10) 
            {
                cnt++;
                carry = 1;
            } else {
                carry = 0;
            }
            i--; j--;
        }

        if (cnt == 0) cout << "No carry operation.\n";
        else if (cnt == 1) cout << "1 carry operation.\n";
        else cout << cnt << " carry operations.\n";
    }
}
