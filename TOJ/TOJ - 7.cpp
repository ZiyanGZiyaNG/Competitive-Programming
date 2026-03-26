#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int t; cin >> t;
	while (t--)
	{
		long long int n; cin >> n;
		vector<int> a(n + 1);
		for (long long int i = 0; i <= n; i++) cin >> a[i];
		for (long long int i = 0; i <= n; i++)
		{
			vector<int> v;
			for (long long int i = 0; i < a.size() - 1; i++)
			{
				v.emplace_back(a[i + 1] - a[i]);
			}
			a = v;
		}
		cout << a[0] << '\n';
	}
}
