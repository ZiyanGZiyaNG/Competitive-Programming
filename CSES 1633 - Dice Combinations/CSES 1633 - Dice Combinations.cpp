#include <iostream>
using namespace std;
int main()
{
	long long int n; cin >> n;
	int dp[n + 1];
	for (int i = 0; i <= n; i++) dp[i] = 0;
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		long long count = 0;
		for (int k = 1; k <= 6; k++)
		{
			if (i - k >= 0)
			{
				dp[i] = (dp[i] + dp[i - k]) % 1000000007LL;	
			}
		}
	}
	cout << dp[n];
}
