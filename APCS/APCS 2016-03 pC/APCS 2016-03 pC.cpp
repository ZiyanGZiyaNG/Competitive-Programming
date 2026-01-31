#include <iostream>
using namespace std;
bool y[10000000] = {false};
int main()
{
	int n; cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int l, r; cin >> l >> r;
		if (l == r) continue;
		for (int j = l; j < r; j++)
		{
			y[j] = true;
		}
	}
	
	for (int i = 0; i < 10000000; i++)
	{
		if (y[i] == true) ans++;
	}
	cout << ans;
}
