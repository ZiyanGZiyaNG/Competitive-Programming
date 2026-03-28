#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    string a, b;
    cin >> a >> b;
    
    bool py = false;
    
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '0')
        {
            if (i - 1 >= 0 && b[i - 1] == '0') py = true;
            if (i + 1 < n && b[i + 1] == '0') py = true;
        }
    }
    
    if (py) cout << "FENESTRATION FORTIFICATION FAILURE!\n";
    else cout << "FENDED OFF!\n";
    
    return 0;
}
