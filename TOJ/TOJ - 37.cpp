#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while (getline(cin, s))
	{
		stringstream ss(s);
		int x;
		int c = 0;
		while (ss >> x)
		{
			c++;
		}
		cout << c << '\n';
	}
}
