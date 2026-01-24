#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() 
{
    vector<string> v;
    string s;

    while (getline(cin, s)) {
        bool seen = false;

        for (int i = 0; i < v.size(); i++) 
        {
            if (v[i] == s) 
            {
                seen = true;
                break;
            }
        }

        if (seen) cout << "YES\n";
        else cout << "NO\n";

        v.push_back(s);
    }
}
