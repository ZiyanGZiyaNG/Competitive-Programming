// 轉移式 dp[1] = max(dp[i - 1], dp[i - 2] + v[i]);
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n + 1);
		for (int i = 1; i <= n; i++) cin >> v[i];
		vector<int> dp(n + 1); dp[0] = 0;
		dp[1] = max(0, v[1]);
		for (int i = 2; i <= n; i++)
		{
			dp[i] = max(dp[i - 1], dp[i - 2] + v[i]);
		}
		cout << dp[n] << '\n';
	}
}
