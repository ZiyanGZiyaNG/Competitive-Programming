#include <bits/stdc++.h>
using namespace std;
int main()
{
	int l, k, n; cin >> l >> k >> n;
	vector<int> a(n + 1);
	int mn = INT_MAX;
	int loc = -1;
	int ans = (l + k - 1) / k;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		if (abs(ans - a[i]) < mn)
		{
			mn = min(abs(ans - a[i]), mn);
			loc = i;
		}
	}
	cout << loc;
}
