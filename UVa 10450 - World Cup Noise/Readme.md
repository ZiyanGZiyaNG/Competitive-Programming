<div align="center">
  <h1>題解</h1>
  <p>UVa 10450 - World Cup Noise
  | https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1391
</p>
</div>

<p align="center">
 這題原本沒什麼想法，偷看了一下SCIST的解法
</p>
<p align="center">
  if $$f(n) = 1$$ than $$f(n - 1) = 0$$
</p>
<p align="center">
  if $$f(n) = 0$$ than $$f(n - 1) = 1 or 0$$
</p>
<p align="center">
 BTW 看到有人用fib解 | https://blog.csdn.net/mobius_strip/article/details/39801239
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
