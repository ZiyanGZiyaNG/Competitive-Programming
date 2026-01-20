#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int n, m; 
int mp[50][50];
vector<pair<int, int>> ans;
bool vis[50][50];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int sx, int sy, int w)
{
	int count = mp[sx][sy];
	memset(vis, 0, sizeof(vis));
	queue<pair<int, int>> q;
	q.push({sx, sy});
	vis[sx][sy] = true;
	
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;
		for (int d = 0; d < 4; d++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			
			if (nx >= n or nx < 0 or ny >= m or ny < 0) continue;
			if (vis[nx][ny]) continue;
			
			if (abs(nx - sx) + abs(ny - sy) <= w) count += mp[nx][ny];
			vis[nx][ny] = true;
			q.push({nx, ny});
		}
		
	}
	return count;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mp[i][j];
		}
	}
	
	int x;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			x = mp[i][j];
			if (bfs(i, j, x) % 10 == x)
			ans.push_back({i, j});
		}
	}
	cout << ans.size() << "\n";
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second << "\n";
	} 
}
