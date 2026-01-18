/*
#include <sstream> -> stringstream
stringstream -> 用來把整段string取值(跳過空白的)
*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore(); 

    for (int i = 0; i < t; i++)
    {
        string l;
        getline(cin, l);          
        stringstream s(l);      
        long long sum = 0;
        long long x;

        while (s >> x)
        {
            sum += x;
        }

        cout << sum << "\n";
    }
}
