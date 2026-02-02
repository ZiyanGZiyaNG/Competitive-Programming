#include <iostream>
using namespace std;
int n;
int len;
int bit[200001];
int lowbit(int x)
{
	return x & -x;
}
void add(int pos, int data)
{
	while (pos <= len)
	{
		bit[pos] += data;
		pos += lowbit(pos);
	}
	return;
}
int sum(int pos)
{
	int res = 0;
	while (pos > 0)
	{
		res += bit[pos];
		pos -= lowbit(pos);
	}
	return res;
}
int main()
{
	cin >> n;
	len = 2 * n;
	int a[len];
	for (int i = 0; i < len; i++) cin >> a[i];
	int p1[n + 1], p2[n + 1];
	for (int i = 0; i <= n; i++)
	{
		p1[i] = -1; p2[i] = -1;
	}
	for (int i = 0; i < len; i++)
	{
		if (p1[a[i]] == -1) p1[a[i]] = i;
		else p2[a[i]] = i;
	}
	
	long long int ans = 0;

	for (int i = 0; i <= len; i++) bit[i] = 0;
	for (int i = 1; i <= n; i++)
	{
		int l = p1[i] + 1, r = p2[i] + 1;
		int cnt = sum(r - 1) - sum(l);
		ans += cnt;
		add(l, 1);
		add(r, 1);
	}
	cout << ans;
}
