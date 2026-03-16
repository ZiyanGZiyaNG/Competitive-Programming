// 根號分塊
#include <bits/stdc++.h>
using namespace std;
int n, q;
int main()
{
	cin >> n >> q;
	int B = sqrt(n);
	vector<int> a(n + 1);
	vector<int> bit(n / B + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		if (i % B == 0) bit[i/B] = a[i];
		else bit[i/B] = min(bit[i/B], a[i]);
	}
	while (q--)
	{
		int l, r; cin >> l >> r;
		int ans = 1e9;
		for (int i = l; i <= r;)
		{
			if ((i / B) * B >= l and (i / B) * B + B - 1 <= r)
			{
				ans = min(bit[i / B], ans);
				i += B;
			}
			else
			{
				ans = min(ans, a[i]);
				i++;
			}
		}
		cout << ans << '\n';
		
	}
}
