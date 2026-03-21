#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> tree;
void build(int l, int r, int id)
{
	if (l == r)
	{
		cin >> tree[id];
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, 2 * id);
	build(mid + 1, r, 2 * id + 1);
	tree[id] = max(tree[id * 2], tree[2 * id + 1]);
}
int query(int ql, int qr, int l, int r, int id)
{
	if (ql <= l and r <= qr) return tree[id];
	int mid = (l + r) / 2;
	if (qr <= mid) return query(ql, qr, l, mid, 2 * id);
	else if (ql > mid) return query(ql, qr, mid + 1, r, 2 * id + 1);
	else
	{
		return max(query(ql, mid, l, mid, 2 * id), query(mid + 1, qr, mid + 1, r, 2 * id + 1));
	}
}
void upload(int i, int val, int l, int r, int id)
{
	if (i < l or i > r) return;
	if (l == r) 
	{
		tree[id] = val;
		return;	
	}
	int mid = (l + r) / 2;
	upload(i, val, l, mid, 2 * id);
	upload(i, val, mid + 1, r, 2 * id + 1);
	tree[id] = max(tree[2 * id], tree[2 * id + 1]);
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	tree.resize(4 * n + 1);
	build(1, n, 1);
	int q; cin >> q;
	
	while (q--)
	{
		char w; cin >> w;
		if (w == 'C')
		{
			int a, b; cin >> a >> b; // index:a change to b
			upload(a, b, 1, n, 1);
		}
		else if (w == 'Q')
		{
			int a, b; cin >> a >> b;
			int x = query(a, b, 1, n, 1);
			cout << x / 2 << '\n';
		}
	}
}
