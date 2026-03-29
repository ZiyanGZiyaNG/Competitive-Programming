#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int t; cin >> t;
	while (t--)
	{
		long long int n; cin >> n;
		vector<long long int> a(10, 0);
		for (long long int i = 1; i <= n; i *= 10)
		{
			long long int h = n / (i * 10);
			long long int c = (n / i) % 10;
			long long int l = n % i;
			for (long long int d = 1; d <= 9; d++)
			{
				if (c > d) a[d] += (h + 1) * i;
				else if (c == d) a[d] += h * i + l + 1;
				else a[d] += h * i;
			}			
			if (c > 0) a[0] += (h - 1) * i + i;
			else if (c == 0) a[0] += (h - 1) * i + l + 1;
		}
		for (long long int i = 0; i < 10; i++) cout << a[i] << " ";
		cout << '\n';
	}
}
