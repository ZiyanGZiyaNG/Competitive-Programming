#include <iostream>
using namespace std;
int main()
{
	long long int n; cin >> n;
	for (int k = 0; k < n; k++)
	{
		long long int s; cin >> s;
		long long int dp[2][2];
		dp[0][1] = dp[0][0] = 1;
		for (int i = 1; i < s; i++)
		{
			dp[i % 2][1] = dp[(i - 1) % 2][0];
			dp[i % 2][0] = dp[(i - 1) % 2][1] + dp[(i - 1) % 2][0];
		}
		cout << "Scenario #" << k + 1 << ":" << "\n" << dp[(s - 1) % 2][1] + dp[(s - 1) % 2][0] << "\n";
		cout << "\n";
	}
	
}
