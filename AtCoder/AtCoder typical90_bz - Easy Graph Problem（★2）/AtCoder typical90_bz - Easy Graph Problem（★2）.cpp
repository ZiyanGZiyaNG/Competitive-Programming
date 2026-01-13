#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, m; cin >> n >> m;
	int cnt = 0;
	vector<vector<int>> list(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		list[a].push_back(b);
		list[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		int num = 0;
		for (int j = 0; j < list[i].size(); j++)
		{
			if (list[i][j] < i)
			{
				num++;
			}
		}
		if (num == 1) cnt++;
	}
	cout << cnt;
}
