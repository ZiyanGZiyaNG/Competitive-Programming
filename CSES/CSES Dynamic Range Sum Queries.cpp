#include <bits/stdc++.h>
using namespace std;
long long int n, q;
vector<long long int> v;
vector<long long int> tree;
void build(long long int l, long long int r, long long int id)
{
	if (l == r)
	{
		tree[id] = v[l];
		return;
	}
	long long int mid = (l + r) / 2;
	build(l, mid, 2 * id);
	build(mid + 1, r, 2 * id + 1);
	tree[id] = (tree[2 * id] + tree[2 * id + 1]);
}
long long int query(long long int ql, long long int qr, long long int l, long long int r, long long int id)
{
	if (ql <= l and r <= qr) return tree[id];
	long long int mid = (l + r) / 2;
	if (qr <= mid) return query(ql, qr, l, mid, 2 * id);
	else if (ql > mid) return query(ql, qr, mid + 1, r, 2 * id + 1);
	else return query(ql, mid, l, mid, 2 * id) + query(mid + 1, qr, mid + 1, r, 2 * id + 1);
}
void upload(long long int i, long long int val, long long int l, long long int r, long long int id)
{
	if (l == r) 
	{
		tree[id] += val;
		return;	
	}
	long long int mid = (l + r) / 2;
	if (i <= mid) upload(i, val, l, mid, 2 * id);
	else if (i > mid) upload(i, val, mid + 1, r, 2 * id + 1);
	tree[id] = tree[2 * id] + tree[2 * id + 1];
}
int main()
{
	cin >> n >> q;
	v.resize(n + 1);
	tree.resize(4 * n + 1);
	for (long long int i = 1; i <= n; i++) cin >> v[i];
	build(1, n, 1);
	while (q--)
	{
		long long int w; cin >> w;
		if (w == 1)
		{
			long long int k, u; cin >> k >> u;
			long long int diff = u - v[k];
			v[k] = u;
			upload(k, diff, 1, n, 1);
		}
		else if (w == 2)
		{
			long long int l, r; cin >> l >> r;
			cout << query(l, r, 1, n, 1) << '\n';
		}
	}
}
