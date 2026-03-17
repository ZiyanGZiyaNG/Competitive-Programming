#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> a;
vector<long long> tree;
vector<long long> lazytag;

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
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

void push(int l, int r, int id)
{
	if (l == r) return;
	if (lazytag[id] == 0) return;

	int mid = (l + r) / 2;
	long long tag = lazytag[id];

	lazytag[2 * id] += tag;
	tree[2 * id] += 1LL * (mid - l + 1) * tag;

	lazytag[2 * id + 1] += tag;
	tree[2 * id + 1] += 1LL * (r - mid) * tag;
	lazytag[id] = 0;
}

void upload(int ql, int qr, long long val, int l, int r, int id)
{
	if (ql <= l && r <= qr)
	{
		tree[id] += 1LL * (r - l + 1) * val;
		lazytag[id] += val;
		return;
	}
	push(l, r, id);
	int mid = (l + r) / 2;
	if (qr <= mid) upload(ql, qr, val, l, mid, 2 * id);
	else if (ql > mid) upload(ql, qr, val, mid + 1, r, 2 * id + 1);
	else
	{
		upload(ql, mid, val, l, mid, 2 * id);
		upload(mid + 1, qr, val, mid + 1, r, 2 * id + 1);
	}
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

long long query(int ql, int qr, int l, int r, int id)
{
	if (ql <= l && r <= qr) return tree[id];
	push(l, r, id);
	int mid = (l + r) / 2;
	if (qr <= mid) return query(ql, qr, l, mid, 2 * id);
	else if (ql > mid) return query(ql, qr, mid + 1, r, 2 * id + 1);
	else
	{
		return query(ql, mid, l, mid, 2 * id) +
			   query(mid + 1, qr, mid + 1, r, 2 * id + 1);
	}
}

int main()
{
	cin >> n;
	a.resize(n + 1);
	tree.resize(4 * n + 1);
	lazytag.resize(4 * n + 1);

	for (int i = 1; i <= n; i++) cin >> a[i];

	build(1, n, 1);

	int q;
	cin >> q;
	while (q--)
	{
		int v;
		cin >> v;
		if (v == 1)
		{
			int l, r;
			long long val;
			cin >> l >> r >> val;
			upload(l, r, val, 1, n, 1);
		}
		else if (v == 2)
		{
			int x, y;
			cin >> x >> y;
			cout << query(x, y, 1, n, 1) << '\n';
		}
	}
}
