#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m; cin >> n >> m;
	long long int sum = 0;
	vector<int> t(n);
	for (int i = 0; i < n; i++) cin >> t[i];
	vector<int> s(m);
	vector<int> e(m);
	for (int i = 0; i < m; i++) cin >> s[i] >> e[i];
	sort(t.begin(), t.end());
	sort(s.begin(), s.end());
	sort(e.begin(), e.end());
	int i_x = 0, j_x = 0, act = 0;
	for (int i = 0; i < n; i++)
	{
		int tt = t[i];
		
		while (i_x < m and s[i_x] <= tt)
		{
			i_x++;
			act++;
		}
		while (j_x < m and e[j_x] < tt) 
		{
			j_x++;
			act--; 
		}
		sum += act;
	}
	cout << sum;
}
