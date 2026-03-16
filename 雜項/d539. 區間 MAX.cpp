#include <bits/stdc++.h>
using namespace std;

struct SegTree
{
    int n;
    vector<int> t;
    vector<int> tree;

    SegTree(int _n)
    {
        n = _n;
        t.resize(n + 1);
        tree.resize(4 * n + 1);
    }

    void build(int l, int r, int id)
    {
        if (l == r)
        {
            tree[id] = t[l]; return;
    	}
        int mid = (l + r) / 2;
        build(l, mid, 2 * id);
        build(mid + 1, r, 2 * id + 1);
        tree[id] = max(tree[2 * id], tree[2 * id + 1]);
    }

    int query(int ql, int qr, int l, int r, int id)
    {
        if (ql <= l && r <= qr) return tree[id];
        int mid = (l + r) / 2;
        if (qr <= mid) return query(ql, qr, l, mid, 2 * id);
        else if (ql > mid) return query(ql, qr, mid + 1, r, 2 * id + 1);
        else
        {
            return max(query(ql, mid, l, mid, 2 * id), query(mid + 1, qr, mid + 1, r, 2 * id + 1));
        }
    }
};

int main()
{
    int n;
    cin >> n;

    SegTree seg(n);

    for (int i = 1; i <= n; i++) cin >> seg.t[i];

    seg.build(1, n, 1);

    int m;
    cin >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        int l = min(a, b);
        int r = max(a, b);
        cout << seg.query(l, r, 1, n, 1) << '\n';
    }
}
