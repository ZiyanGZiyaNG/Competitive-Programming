#include <bits/stdc++.h>
using namespace std;
int main()
{
	int v;
	while (cin >> v)
	{
		int n; cin >> n;
		vector<pair<int, int>> w(n + 1);
		for (int i = 1; i <= n; i++) cin >> w[i].first >> w[i].second;
		vector<int> dp(v + 1);
		dp[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = w[i].first; j <= v; j++)
			{
				dp[j] = max(dp[j], dp[j - w[i].first] + w[i].second);
			}  
		}
		cout << dp[v] << '\n';	
	}
}
