#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin >> n;
	int mx = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		mx = max(a, mx);
	}
	cout << mx;
}
