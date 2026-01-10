#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n, m, q;
int mp[500][500];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int sx, sy;
bool vis[500][500];
bool a[500][500];
bool boom[500][500];
void ex(int bx, int by, int r, int &cnt, queue<pair<pair<int,int>, int>> &boob)
{
	bool c[500][500];
	memset(c, 0, sizeof(c));
	
	queue<pair<pair<int,int>, int>> qb;
	c[bx][by] = true;
	qb.push({{bx, by}, 0});
	
	while (!qb.empty())
	{
		auto cur = qb.front();
		qb.pop();
		int bbx = cur.first.first;
		int bby = cur.first.second;
		int bbd = cur.second;
		
		if (!a[bbx][bby])
		{
			a[bbx][bby] = true;
			cnt++;
		}
		
		if (mp[bbx][bby] > 0 and !boom[bbx][bby])
		{
			boom[bbx][bby] = true;
			boob.push({{bbx, bby}, mp[bbx][bby]});
		}
		
		if (bbd == r) continue;
		
		for (int d = 0; d < 4; d++)
		{
			int nx = bbx + dx[d];
			int ny = bby + dy[d];
			if (nx >= n or nx < 0 or ny >= m or ny < 0) continue;
			if (c[nx][ny]) continue;
			if (mp[nx][ny] == -1) continue;
			
			qb.push({{nx, ny}, bbd + 1});
			c[nx][ny] = true;
		}
	}
	
	
}
void bfs(int x, int y)
{
	int cnt = 0;
	memset(vis, false, sizeof(vis));
	memset(a, false, sizeof(a));
	memset(boom, false, sizeof(boom));
	queue<pair<pair<int,int>, int>> qq;
	queue<pair<pair<int,int>, int>> boob;
	int d = 0;
	vis[x][y] = true;
	qq.push({{x, y}, d});
	
	
	
	while (!qq.empty())
	{
		auto cur = qq.front();
		qq.pop();
		int xx = cur.first.first;
		int yy = cur.first.second;
		int dd = cur.second;
		
		if (mp[xx][yy] > 0 and !boom[xx][yy])
		{
			boom[xx][yy] = true;
			boob.push({{xx, yy}, mp[xx][yy]});
		}
		
		while (!boob.empty())
		{
		    auto b = boob.front(); boob.pop();
		    ex(b.first.first, b.first.second, b.second, cnt, boob);
		}
		
		if (!a[xx][yy])
		{
			a[xx][yy] = true;
			cnt++;
		}
		
		for (int i = 0; i < 4; i++)
		{
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (nx >= n or nx < 0 or ny >= m or ny < 0) continue;
			if (vis[nx][ny]) continue;
			if (mp[nx][ny] == -1) continue;
			
			qq.push({{nx, ny}, dd + 1});
			vis[nx][ny] = true;
		}
		
		if (cnt >= q)
		{
			cout << dd;
			return;
		}
		
	}
}

int main()
{
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mp[i][j];
			if (mp[i][j] == -2)
			{
				sx = i; sy = j;
			}
		}
	}
	bfs(sx, sy);
	
}
