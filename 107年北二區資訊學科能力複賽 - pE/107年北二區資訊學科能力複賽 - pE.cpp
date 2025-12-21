#include <iostream>
using namespace std;
static const long long MOD = 1e8+7;

int main()
{
    int n;cin >> n;
    long long dp[n + 1][2][3];
    for (int i = 0; i <= n; i++)
        for (int l = 0; l < 2; l++)
            for (int p = 0; p < 3; p++)
                dp[i][l][p] = 0;


    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int l = 0; l < 2; l++)
        {
            for (int p = 0; p < 3; p++)
            {
                long long val = dp[i - 1][l][p];
                dp[i][l][0] = (dp[i][l][0] + val) % MOD;
                if (l == 0)
                {
                    dp[i][1][0] = (dp[i][1][0] + val) % MOD;
                }

                if (p < 2)
                {
                    dp[i][l][p + 1] = (dp[i][l][p + 1] + val) % MOD;
                }
            }
        }
    }

 
    long long ans = 0;
    for (int l = 0; l < 2; l++)
        for (int p = 0; p < 3; p++)
            ans = (ans + dp[n][l][p]) % MOD;

    cout << ans << endl;
    return 0;
}
