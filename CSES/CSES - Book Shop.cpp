#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, x; cin >> n >> x;
	vector<int> h(n + 1);
	for (int i = 1; i <= n; i++) cin >> h[i];
	vector<int> s(n + 1);
	for (int i = 1; i <= n; i++) cin >> s[i];
	vector<int> dp(x + 1); dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = x; j >= h[i]; j--)
		{
			if (x - h[i] >= 0)
			{
				dp[j] = max(dp[j], dp[j - h[i]] + s[i]);		
			}
		}
	}
	cout << dp[x];
}
