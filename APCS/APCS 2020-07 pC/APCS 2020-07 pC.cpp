#include <iostream>
using namespace std;
int main()
{
	int n, m; cin >> n >> m;
	int p[n];
	int s = 0;
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 0; i < m; i++)
	{
		int x = 0;
		int q; cin >> q;
		while (x < q)
		{
			
			x += p[s];
			s = (s + 1) % n;
		}
	}
	cout << s;
}
