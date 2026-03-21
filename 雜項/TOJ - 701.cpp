#include <bits/stdc++.h>
using namespace std;
vector<int> boss;
int find(int a)
{
	if (boss[a] == a) return a;
	boss[a] = find(boss[a]);
	return boss[a];
}
int main()
{
	int n, q; cin >> n >> q;
	boss.resize(n + 1);
	for (int i = 1; i <= n; i++) boss[i] = i;
	while (q--)
	{
		int cmd, x, y; cin >> cmd >> x >> y;
		int bx = find(x);
		int by = find(y);
		if (cmd == 0)
		{
			if (bx == by) cout << "YES\n";
			else cout << "NO\n";
		}
		else if (cmd == 1)
		{
			boss[bx] = by;
		}
	}
}
