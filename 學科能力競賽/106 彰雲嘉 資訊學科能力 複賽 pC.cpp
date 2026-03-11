#include <bits/stdc++.h>
using namespace std;
int main()
{	
	vector<int> f;
	f.emplace_back(0);
	f.emplace_back(1);
	int n = 2; 
	while (true)
	{
		f.emplace_back(f[n - 1] + f[n - 2]);
		if (f[n] > 1000000) break;
		n++;
	}
	int t; cin >> t;
	for (int i = 0; i < t; i++)
	{
		int x; cin >> x;
		bool yn = false;
		for (int a = 0; a < n; a++)
		{
			
			if (x == f[a] and yn == false) 
			{
				cout << a << '\n';
				yn = true;
			}
		}
		if (!yn) cout << -1 << "\n";
	}
}
