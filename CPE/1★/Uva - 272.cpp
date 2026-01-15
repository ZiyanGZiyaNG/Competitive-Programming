#include <iostream>
using namespace std;
int main()
{
    int n = 1;
    char c;
    while (cin.get(c))
    {
        if (c == '"')
        {
            n++;
            if (n % 2 == 0) cout << "``";
            else cout << "''";
        }
        else cout << c;
        
    }
    
}