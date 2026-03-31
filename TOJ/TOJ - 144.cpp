// 求樹直徑
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> e;
vector<int> dp;
int d;
void dfs(int s, int t)
{
	for (int i = 0; i < e[s].size(); i++)
	{
		int to = e[s][i];
		if (to == t) continue;
		dfs(to, s);
		d = max(d, dp[to] + dp[s] + 1);
		dp[s] = max(dp[to] + 1, dp[s]);
	}
}
int main()
{
	int n, m; cin >> n >> m;
	e.resize(n);
	dp.resize(n);
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(0, -1);
	cout << d;
}
