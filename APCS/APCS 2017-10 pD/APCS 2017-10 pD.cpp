#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long int n; cin >> n;
	long long int w[n], f[n], s[n];
	for (int i = 0; i < n; i++) cin >> w[i];
	for (int i = 0; i < n; i++) cin >> f[i];
	
	for (int i = 0; i < n; i++) s[i] = i;
	
	
	sort(s, s + n, [&](int a, int b)
	{
		return w[a] * f[b] < w[b] * f[a];
	});
	
	
	long long int ans = 0;
	long long int sum = 0;
	for (int i = 0; i < n - 1; i++)
	{
		sum += w[s[i]];
		ans += sum * f[s[i + 1]];
	}
	cout << ans;
}
