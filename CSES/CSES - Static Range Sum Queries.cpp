#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long int n, q; cin >> n >> q;
	long long int x[n + 1];
	for (int i = 1; i <= n; i++) cin >> x[i];
	long long int pre[n + 1];
	pre[0] = 0;
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + x[i];
	
	while (q--)
	{
		long long int a, b; cin >> a >> b;
		long long int l = min(a, b), r = max(a, b);
		cout << pre[r] - pre[l - 1] << "\n";
	}
}
