# 題解 — ZeroJudge c878

題目連結  
https://zerojudge.tw/ShowProblem?problemid=c878

---

## 題目說明

本題要求計算長度為 `n` 的出勤紀錄數量，並需同時滿足以下限制條件：

1. `L`（Late）最多只能出現 **一次**
2. `P`（Present）不能 **連續出現三次**
3. 其餘狀態皆視為合法

請輸出所有符合條件的序列數量，結果需對指定模數取模。

---

## 解題思路（Dynamic Programming）

由於題目同時限制：

- 是否已經使用過一次 `L`
- 目前連續出現 `P` 的次數  

單純用一維或二維 DP 無法完整描述狀態，因此必須使用 **三維 DP**。
$dp[i][l][p]$
表示：

- 已考慮前 `i` 天
- `l` ∈ {0,1}：是否已經使用過一次 `L`
- `p` ∈ {0,1,2}：目前連續出現 `P` 的次數
- 值為符合條件的合法序列數量

---

## 初始狀態

$dp[i][l][p]$

---

##  DP 狀態定義
表示：

- 已考慮前 `i` 天
- `l` ∈ {0,1}：是否已經使用過一次 `L`
- `p` ∈ {0,1,2}：目前連續出現 `P` 的次數
- 值為符合條件的合法序列數量

---

##  初始狀態

$dp[0][0][0] = 1$
表示第 0 天尚未開始：
- 尚未遲到
- 沒有連續 P
- 只有一種合法狀態

---

##  狀態轉移說明

假設從 `dp[i-1][l][p]` 轉移到第 `i` 天：

### _1._ 今日選擇非 `P` 狀態（例如 A）

- 連續 `P` 次數歸零
 ---

### _2._ 今日選擇 `L`（遲到）

- 只能在尚未使用過 `L` 的情況下使用
- 使用後 `l` 變為 1
- 連續 `P` 次數歸零
$if l == 0:
dp[i][1][0] += dp[i-1][0][p]$

---

### _3._ 今日選擇 `P`（出席）

- 僅當 `p < 2` 時允許
- 連續 `P` 次數加一

$if p < 2:
dp[i][l][p+1] += dp[i-1][l][p]$

---

##  為什麼不會違反限制？

- `l` 確保 `L` 最多出現一次
- `p < 2` 確保不會出現三個連續 `P`
- 所有非法狀態在轉移時即被排除

---

##  C++ 參考實作

```cpp
#include <iostream>
using namespace std;

static const long long MOD = 100000007;

int main()
{
    int n;
    cin >> n;

    long long dp[n + 1][2][3];

    for (int i = 0; i <= n; i++)
        for (int l = 0; l < 2; l++)
            for (int p = 0; p < 3; p++)
                dp[i][l][p] = 0;

    dp[0][0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int l = 0; l < 2; l++)
        {
            for (int p = 0; p < 3; p++)
            {
                long long val = dp[i - 1][l][p];
                if (val == 0) continue;

                dp[i][l][0] = (dp[i][l][0] + val) % MOD;

                if (l == 0)
                {
                    dp[i][1][0] = (dp[i][1][0] + val) % MOD;
                }

                if (p < 2)
                {
                    dp[i][l][p + 1] = (dp[i][l][p + 1] + val) % MOD;
                }
            }
        }
    }

    long long ans = 0;
    for (int l = 0; l < 2; l++)
        for (int p = 0; p < 3; p++)
            ans = (ans + dp[n][l][p]) % MOD;

    cout << ans << endl;
    return 0;
}
