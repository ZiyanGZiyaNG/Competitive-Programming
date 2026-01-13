#  TOJ 508 — 完美河道

🔗 題目連結  
https://toj.tfcis.org/oj/pro/508/

---

##  題目說明

給定一個 `n × m` 的地圖，每個格子包含 `0 ~ 9` 的數字。  
河道必須 **從高度 9 開始，每一步只能走到高度剛好少 1 的相鄰格子（上下左右）**，  
直到走到高度 `0` 為止。

請計算 **所有合法河道的總數量**。

---

##  解題思路（DFS + DP）

###  為什麼不能只用 DFS？

如果單純從每個 `9` 開始 DFS，  
會對同一個位置 **重複計算大量子路徑**，導致：

- 狀態重複
- 搜尋樹爆炸
- 最終 **TLE**

---

## 正確作法：DFS + 記憶化（DP）

### _1._ 狀態定義
$dp[x][y] =$ 從座標 $(x, y)$ 出發，能走到高度 0 的所有合法路徑數

---

### _2._ 遞迴終止條件

- 若 `mp[x][y] == 0`  
  → 已成功走到終點，回傳 `1`
- 若該格子已計算過  
  → 直接回傳 $dp[x][y]$

---

### _3._ 狀態轉移（DFS）

- 從 $(x, y)$ 嘗試往四個方向移動
- 只能走到 **高度 = 當前高度 − 1** 的格子
- 將所有可行方向的結果加總

---

### _4._ 為什麼這樣不會 TLE？

- 每個格子 **最多只會被完整 DFS 一次**
- 之後皆由 `dp` 直接回傳
- 時間複雜度大幅下降

---

##  演算法流程

1. 讀入地圖
2. 對每個高度為 `9` 的格子作為起點
3. 使用 DFS 計算其可行河道數
4. 利用 `dp` 記憶化避免重複計算
5. 將所有起點結果加總

---

##  C++ 參考實作

```cpp
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

long long dfs(int x, int y)
{
    if (mp[x][y] == 0) return 1;
    if (visit[x][y]) return dp[x][y];

    visit[x][y] = true;
    long long count = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < n && 0 <= ny && ny < m)
        {
            if (mp[nx][ny] == mp[x][y] - 1)
            {
                count += dfs(nx, ny);
            }
        }
    }

    dp[x][y] = count;
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

    memset(visit, false, sizeof(visit));

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
