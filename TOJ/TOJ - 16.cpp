#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<int> s(n);
		for (int i = 0; i < n; i++) cin >> s[i];
		vector<bool> v(300001, false);
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (i != j and s[i] > 0 and s[j] > 0) v[s[i] + s[j]] = true;
			}
		}	
		int q; cin >> q;
		while (q--)
		{
			int w; cin >> w;
			if (v[w] == true) cout << "Good!\n";	
			else cout << "So Bad!\n";
		}	
	}
}
