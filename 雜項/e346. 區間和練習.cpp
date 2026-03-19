#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n, q; cin >> n;
	vector<long long int> a(n + 1);
	vector<long long int> pre(n + 1);
	pre[0] = 0;
	for (long long int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];	
	}
	cin >> q;
	while (q--)
	{
		long long int l, r; cin >> l >> r;
		cout << pre[r] - pre[l - 1] << '\n';
	}

}
