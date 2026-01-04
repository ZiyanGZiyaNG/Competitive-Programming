#include <iostream>
#include <climits>
using namespace std;

int mp[100][100];
bool vis[100][100];
int n, m;
long long sumv = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void walk(int x, int y)
{
    vis[x][y] = true;
    sumv += mp[x][y];

    while (true)
    {
        int bestX = -1, bestY = -1;
        int bestVal = INT_MAX;

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny]) continue;

            if (mp[nx][ny] < bestVal)
            {
                bestVal = mp[nx][ny];
                bestX = nx;
                bestY = ny;
            }
        }

        if (bestX == -1) break;

        x = bestX;
        y = bestY;
        vis[x][y] = true;
        sumv += mp[x][y];
    }
}

int main()
{

    cin >> n >> m;

    int sx = 0, sy = 0;
    int mn = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
            vis[i][j] = false;

            if (mp[i][j] < mn)
            {
                mn = mp[i][j];
                sx = i; sy = j;
            }
        }
    }

    walk(sx, sy);
    cout << sumv;
}
