<div align="center">
  <h1>題解</h1>
  <p>CSES 1633 - Dice Combinations
  | https://cses.fi/problemset/task/1633/
</p>
</div>

<p align="center">
 骰子骰的組合數等於n
</p>
<p align="center">
  → 用DP展開式 $$f(n) = f(n - 1) + f(n - 2) + f(n - 3) + f(n - 4) + f(n - 5) + f(n - 6)$$
</p>
<p align="center">
  但有時 $$(n - 1) < 0$$ 或 $$(n - 2) < 0$$ 或 $$(n - 3) < 0$$ 或 $$(n - 4) < 0$$ 或 $$(n - 5) < 0$$ 或 $$(n - 6) <  0$$
</p>
<p align="center">
  所以用 $$n$$ $$k$$ 去做判斷,並且要去 % $$mod$$ 不然會過大爆開
</p>

<p align="center">
  程式如下:
</p>

``` cpp
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
