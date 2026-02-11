#include <iostream>
#include <algorithm>
using namespace std;
int a[300000];
int tree[1200000];

int query(int ql, int qr, int l, int r, int id)
{
	if (ql <= l and r <= qr) return tree[id];
	int mid = (l + r) / 2;
	if (qr <= mid) return query(ql, qr, l, mid, 2 * id);
	else if (ql > mid) return query(ql, qr, mid + 1, r, 2 * id + 1);
	else 
	{
		int li = query(ql, qr, l, mid, 2 * id);
		int ri = query(ql, qr, mid + 1, r, 2 * id + 1);
		if (a[li] < a[ri]) return li;
		else return ri;
	}
}

void build(int l, int r, int id)
{
	if (l == r)
	{
		tree[id] = l;
		return;
	}
	
	int mid = (l + r) / 2;
	build(l, mid, 2 * id);
	build(mid + 1, r, 2 * id + 1);
	int li = tree[id * 2];
	int ri = tree[id * 2 + 1];
	tree[id] = (a[li] < a[ri] ? li : ri);
}

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	long long int pre[n];
	pre[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		pre[i] = pre[i - 1] + a[i]; 
	}
	int l = 0, r = n - 1;
	build(l, r, 1);
	while (l < r)
	{
		int m = query(l, r, 0, n - 1, 1);
		
		long long int suml;
		if (l == m) suml = 0;
		else suml = pre[m-1] - (l>0 ? pre[l-1] : 0);
		long long int sumr;
		if (m == r) sumr = 0;
		else sumr = pre[r] - pre[m];
		
		if (suml > sumr) r = m - 1;
		else l = m + 1;
		if (l == r) 
		{
			cout << a[l];
			break;
		}
		
	}
}
