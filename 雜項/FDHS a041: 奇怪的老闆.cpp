#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<int> v;
vector<int> mn_tree;
vector<int> mx_tree;
void mn_build(int l, int r, int id)
{
	if (l == r)
	{
		mn_tree[id] = v[l];
		return;
	}
	int mid = (l + r) / 2;
	mn_build(l, mid, 2 * id);
	mn_build(mid + 1, r, 2 * id + 1);
	mn_tree[id] = min(mn_tree[2 * id], mn_tree[2 * id + 1]);
}
void mx_build(int l, int r, int id)
{
	if (l == r)
	{
		mx_tree[id] = v[l];
		return;
	}
	int mid = (l + r) / 2;
	mx_build(l, mid, 2 * id);
	mx_build(mid + 1, r, 2 * id + 1);
	mx_tree[id] = max(mx_tree[2 * id], mx_tree[2 * id + 1]);
}
int mx_query(int ql, int qr, int l, int r, int id)
{
	if (ql <= l and r <= qr) return mx_tree[id];
	int mid = (l + r) / 2;
	if (qr <= mid) return mx_query(ql, qr, l, mid, 2 * id);
	else if (ql > mid) return mx_query(ql, qr, mid + 1, r, 2 * id + 1);
	else
	{
		return max(mx_query(ql, mid, l, mid, 2 * id), mx_query(mid + 1, qr, mid + 1, r, 2 * id + 1));
	} 
}
int mn_query(int ql, int qr, int l, int r, int id)
{
	if (ql <= l and r <= qr) return mn_tree[id];
	int mid = (l + r) / 2;
	if (qr <= mid) return mn_query(ql, qr, l, mid, 2 * id);
	else if (ql > mid) return mn_query(ql, qr, mid + 1, r, 2 * id + 1);
	else
	{
		return min(mn_query(ql, mid, l, mid, 2 * id), mn_query(mid + 1, qr, mid + 1, r, 2 * id + 1));
	} 
}
int main()
{
	cin >> n >> q;
	v.resize(n + 1);
	mn_tree.resize(4 * n + 1);
	mx_tree.resize(4 * n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i];
	mn_build(1, n, 1);
	mx_build(1, n, 1);
	while (q--)
	{
		int a, b; cin >> a >> b;
		cout << abs(mx_query(a, b, 1, n, 1) - mn_query(a, b, 1, n, 1)) << '\n';
		
	}
}
