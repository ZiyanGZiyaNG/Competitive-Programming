#include <iostream>
#include <string>
using namespace std;

int main()
{

    int n; 
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int m; 
        cin >> m;

        int x1 = 0, x2 = 0;

   
        int t = m;
        if (t == 0) x1 = 0; 
        while (t > 0)
        {
            if (t % 2 == 1) x1++;
            t /= 2;
        }

        string s = to_string(m);
        int val = 0;
        for (int j = 0; j < (int)s.size(); j++)
        {
            val = val * 16 + s[j] - '0';
        }

      
        int u = val;
        while (u > 0)
        {
            if (u % 2 == 1) x2++;
            u /= 2;
        }

        cout << x1 << " " << x2 << "\n";
    }
}
