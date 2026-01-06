$if (j = 0)$ 

$dp[j] = dp[j] + triangle[i][j];$

$if (j == i)$

$dp[j] = dp[j - 1] + triangle[i][j];$

$else$

$dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];$
