#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> lines;
    string s;
    int mx = 0;

    while (getline(cin, s)) 
    {
        lines.push_back(s);
        if ((int)s.size() > mx) mx = (int)s.size();
    }

    for (int col = 0; col < mx; col++) 
    {
        for (int row = (int)lines.size() - 1; row >= 0; row--) 
        {
            if (col < lines[row].size()) cout << lines[row][col];
            else cout << ' ';
        }
        cout << "\n";
    }
}
