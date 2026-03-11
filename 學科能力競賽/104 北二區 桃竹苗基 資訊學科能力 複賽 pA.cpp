#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int f[100];
	f[0] = 0; f[1] = 1;
	for (int i = 2; i < 100; i++) f[i] = f[i - 1] + f[i - 2];
	long long int t; cin >> t;
	long long int w = t - 1;
	while (t--)
	{
		long long int a, b; cin >> a >> b;
		long long int sum = 0;
		long long int A = min(a, b);
		long long int B = max(a, b);
		for (int i = 0; i < 100; i++)
		{
			if (A <= f[i] and f[i] <= B)
			{
				cout << f[i] << '\n';
				sum++;
			}
		}
		
		cout << sum << '\n';
		if (w != 0) cout << "------\n";
			w--;
	}
}
