#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<int> a;
vector<int> tree;
void build(int l, int r, int id)
{
	if (l == r)
	{
		tree[id] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, 2 * id);
	build(mid + 1, r, 2 * id + 1);
	tree[id] = min(tree[2 * id], tree[2 * id + 1]);
}

int query(int ql, int qr, int l, int r, int id)
{
	if (ql <= l and r <= qr) return tree[id];
	int mid = (l + r) / 2;
	if (qr <= mid) return query(ql, qr, l, mid, 2 * id);
	else if (ql > mid) return query(ql, qr, mid + 1, r, 2 * id + 1);
	else
	{
		return min(query(ql, mid, l, mid, 2 * id), query(mid + 1, qr, mid + 1, r, 2 * id + 1));
	}	
}
int main()
{
	cin >> n >> q;
	a.resize(n + 1);
	tree.resize(4 * n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, n, 1);
	while (q--)
	{
		int x, y; cin >> x >> y;
		 cout << query(x, y, 1, n, 1) << '\n';
	}
}
