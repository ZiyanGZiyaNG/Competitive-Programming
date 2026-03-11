#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<char> v(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i];
	int k; cin >> k;
	vector<char> ans(n + 1);
	while (k--)
	{
		for (int j = 1; j <= n; j++)
		{
			ans[j] = v[a[j]];
		}
		for (int j = 1; j <= n; j++)
		{
			v[j] = ans[j];
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i];
}
