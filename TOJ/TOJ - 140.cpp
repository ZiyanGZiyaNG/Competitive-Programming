#include <bits/stdc++.h>
using namespace std;
int a[3] = {676, 26, 1};
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		int sum = 0;
		for (int i = 0; i < 3; i++) 
		{
			int x = s[i] - 'A';
			sum += x * a[i];
		}
		int w = 1000 * (s[4] - '0') + 100 * (s[5] - '0') + 10 * (s[6] - '0') + (s[7] - '0');
		if (abs(w - sum) <= 100) cout << "nice\n";
		else cout << "not nice\n";
	}
}
