#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n;
int mp[300][300];
bool vis[300][300];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool dfs(int sx, int sy, int h)
{
    if (sx == n - 1 && sy == n - 1) return true;

    vis[sx][sy] = true; 

    for (int d = 0; d < 4; d++)
    {
        int nx = sx + dx[d];
        int ny = sy + dy[d];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; 
        if (vis[nx][ny]) continue;
        if (abs(mp[sx][sy] - mp[nx][ny]) > h) continue;

        if (dfs(nx, ny, h)) return true; 
    }
    return false;
}

int bfs(int sx, int sy, int h)
{
    memset(vis, false, sizeof(vis));
    queue<pair<pair<int,int>, int>> q;
    vis[sx][sy] = true;
    q.push({{sx, sy}, 0});

    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        int x = cur.first.first;
        int y = cur.first.second;
        int dist = cur.second;

        if (x == n - 1 && y == n - 1) return dist;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny]) continue;
            if (abs(mp[x][y] - mp[nx][ny]) > h) continue;

            vis[nx][ny] = true;
            q.push({{nx, ny}, dist + 1});
        }
    }
}

int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mp[i][j];

    int l = 0, r = 1e6;
    int hight = 0;

    while (l <= r)
    {
        int m = l + (r - l) / 2;
        memset(vis, false, sizeof(vis));
        bool ok = dfs(0, 0, m);

        if (ok)
        {
            hight = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    cout << hight << "\n";
    cout << bfs(0, 0, hight) << "\n";
    return 0;
}
