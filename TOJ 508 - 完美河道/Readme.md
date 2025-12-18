<div align="center">
  <h1>題解</h1>
  <p>TOJ 508 - 完美河道
  | https://toj.tfcis.org/oj/pro/508/
</p>
</div>

<p align="center">
 這題我原本想直接DFS過去的但很明顯直接TLE
</p>
<p align="center">
  所以用DP + DFS一起
</p>


<p align="center">
  程式如下:
</p>

``` cpp
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int n, m;
int mp[1000][1000];
bool visit[1000][1000];
long long dp[1000][1000];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

long long dfs(int sx, int sy)
{
    if (mp[sx][sy] == 0) return 1;
    if (visit[sx][sy]) return dp[sx][sy];

    visit[sx][sy] = true;
    long long count = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = sx + dx[i];
        int ny = sy + dy[i];

        if (0 <= nx and nx < n and 0 <= ny and ny < m)
        {
            if (mp[nx][ny] == mp[sx][sy] - 1)
            {
                count += dfs(nx, ny);
            }
        }
    }

    dp[sx][sy] = count;
    return count;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            mp[i][j] = s[j] - '0';
        }
    }

    memset(visit, 0, sizeof(visit));
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == 9)
            {
                ans += dfs(i, j);
            }
        }
    }

    cout << ans;
}
