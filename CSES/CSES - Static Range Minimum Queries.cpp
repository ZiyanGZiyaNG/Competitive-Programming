#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long int a[200001];
struct seg
{
	long long int n;
	vector<long long int> tree;
	seg(long long int _n)
	{
		n = _n;
		tree.resize(4 * n + 1);
	}
	
	void build(long long int l, long long int r, long long int id)
	{
		if (l == r)
		{
			tree[id] = a[l];
			return;
		}
		long long int mid = (l + r) / 2;
		build(l, mid , 2 * id);
		build(mid + 1, r, 2 * id + 1);
		tree[id] = min(tree[id * 2], tree[id * 2 + 1]);
	}
		
	long long int query(long long int ql, long long int qr, long long int l, int r, int id)
	{
		if (ql <= l and r <= qr) return tree[id];
		long long int mid = (l + r) / 2;
		if (ql > mid) return query(ql, qr, mid + 1, r, 2 * id + 1);
		else if (qr <= mid) return query(ql, qr, l, mid, 2 * id);
		else 
		{
			return min(query(ql, qr, mid + 1, r, 2 * id + 1), query(ql, qr, l, mid, 2 * id));
		}
	}
};
 
 
int main()
{
	long long int n, q; cin >> n >> q;
	for (long long int i = 1; i <= n; i++) cin >> a[i];
	seg s(n);
	s.build(1, n, 1);
	for (long long int i = 0; i < q; i++)
	{
		long long int a, b; cin >> a >> b;
		cout << s.query(a, b, 1, n, 1) << "\n";
	}
}
