#  UVa 10450 — World Cup Noise

🔗 題目連結  
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1391

---

##  題目說明

本題要求計算在長度為 `n` 的序列中，  
**不允許出現連續兩個 `1`** 的所有合法 0/1 序列數量。

題目會給多組測資，並要求依照指定格式輸出結果。

---

##  解題觀察

一開始較難直接想到解法，因此參考了 **SCIST 的解題思路**，  
核心規則如下：

- 若 $f(n) = 1$
則前一位 **只能是 0** $f(n - 1) = 0$
- 若  $f(n) = 0$
則前一位 **可以是 0 或 1** $f(n - 1) = 0 or 1$
這代表序列的狀態轉移 **只與前一位有關**，  
非常適合使用 **Dynamic Programming**。

---

##  DP 狀態設計

### _1._ 狀態定義
$dp[i][0] = 長度為 i，且最後一位是 0 的合法序列數
dp[i][1] = 長度為 i，且最後一位是 1 的合法序列數$

---

### _2._ 狀態轉移

- 若最後一位是 `1`，前一位 **只能是 0**
$dp[i][1] = dp[i - 1][0]$

- 若最後一位是 `0`，前一位 **可以是 0 或 1**
$dp[i][0] = dp[i - 1][0] + dp[i - 1][1]$

---

### _3._ 初始化條件
$dp[0][0] = 1
dp[0][1] = 1$

---

##  空間最佳化技巧

由於第 `i` 層只依賴 `i - 1`，  
因此使用 **滾動陣列（2 × 2）** 即可，大幅降低空間使用。

---

##  C++ 參考實作

```cpp
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    for (int k = 0; k < n; k++)
    {
        long long s;
        cin >> s;

        long long dp[2][2];
        dp[0][0] = dp[0][1] = 1;

        for (int i = 1; i < s; i++)
        {
            dp[i % 2][1] = dp[(i - 1) % 2][0];
            dp[i % 2][0] = dp[(i - 1) % 2][0] + dp[(i - 1) % 2][1];
        }

        cout << "Scenario #" << k + 1 << ":\n";
        cout << dp[(s - 1) % 2][0] + dp[(s - 1) % 2][1] << "\n\n";
    }
}
