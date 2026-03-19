#include <bits/stdc++.h>
using namespace std;
long long int n, q;
vector<long long int> a;
vector<long long int> bit;
long long int lowbit(long long int x) { return x&-x; }
void modify(long long int i, long long int val)
{
	while (i <= n)
	{
		bit[i] += val;
		i += lowbit(i);
	}
}
long long int query(long long int x)
{
	long long int sum = 0;
	while (x > 0)
	{
		sum += bit[x];
		x -= lowbit(x);
	}
	return sum;
}
int main()
{
	 cin >> n >> q;
	a.resize(n + 1);
	bit.resize(n + 1);
	for (long long int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		modify(i, a[i]);	
	}
	while (q--)
	{
		long long int w; cin >> w;
		if (w == 0) // 單點修改
		{
			long long int p, x; cin >> p >> x;
			modify(p + 1, x);
		}
		else if (w == 1) // 輸出
		{
			long long int l, r; cin >> l >> r;
			cout << query(r) - query(l) << '\n';
		}
	}	
}
