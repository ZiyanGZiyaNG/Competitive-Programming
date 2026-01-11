#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int r, c;
int mp[1000][1000];
bool vis[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int sx, int sy, int dis)
{
	if (mp[sx][sy] == 2) return -1;
	memset(vis, false, sizeof(vis));
	queue<pair<pair<int,int>, int>> q;
	q.push({{sx, sy}, dis});
	vis[sx][sy] = true;
	
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		int x = cur.first.first;
		int y = cur.first.second;
		int d = cur.second;
		
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (vis[nx][ny]) continue;
			if (mp[nx][ny] == 1) continue;
			if (nx < 0 or nx >= r or ny < 0 or ny >= c) continue;
			
			if (mp[nx][ny] == 2) return d;
			
			vis[nx][ny] = true;
			q.push({{nx, ny}, d + 1});
		}
	}
	return -2;
}



int main()
{
	int a, b;
	cin >> r >> c >> a >> b;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> mp[i][j];
		}
	}
	
	if (bfs(a, b, 0) == -2) cout << "WAKUWAKU";
	else cout << bfs(a, b, 0) + 1;
	
}
