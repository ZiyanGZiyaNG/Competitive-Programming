#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0) break;
		
		
		int m[n];
		for (int i = 0; i < n; i++) cin >> m[i];
		int dp[n];
		dp[0] = m[0];
		int best = 0;
		for (int i = 1; i < n; i++)
		{
			dp[i] = max(dp[i - 1] + m[i], m[i]);
			best = max(best, dp[i]);
		}
		if (best <= 0)
		{
			cout << "Losing streak.\n";
		}
		else
		{
			cout << "The maximum winning streak is " << best << ".\n";
		}
	}
}
