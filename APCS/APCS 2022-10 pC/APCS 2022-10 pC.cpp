/*
APCS：勇者修煉 (2020/10 P3)

A. 題目
一開始有 M×N 的二維陣列 E，陣列內的資料為 -100 ~ +100，代表勇者落腳在該處會得到的經驗值，一開始勇者可以從第一列的任意位置開始，且每一步可以向左、向右、向下走，但不能回頭走過去已經走過的路，請算出勇者走到最後一列後，最多可以得到多少經驗值。

B. 題目出處
2020/10 APCS實作題 #3
本題可於 Zerojudge 中測試，網址如下：
https://zerojudge.tw/ShowProblem?problemid=f314
*/

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main () 
{

    int m, n;
    cin >> m >> n;

    int E[n + 1];
    long long L[n + 2];
    long long R[n + 2];
    long long DP[m + 1][n + 2];

    for (int i = 0; i <= m; i++) 
    {
        for (int j = 0; j <= n + 1; j++) 
        {
            DP[i][j] = 0;
        }
    }

  

    for (int i = 1; i <= m; i++) 
    {
        for (int j = 1; j <= n; j++) cin >> E[j];

        
        L[0] = 0;
        R[n + 1] = 0;

     
        for (int j = 1; j <= n; j++) 
        {
            L[j] = max(L[j - 1], DP[i - 1][j]) + E[j];
        }

        for (int j = n; j >= 1; j--) 
        {
            R[j] = max(R[j + 1], DP[i - 1][j]) + E[j];
        }

        for (int j = 1; j <= n; j++)
        {
            DP[i][j] = max(L[j], R[j]);
        }
    }

    long long ans = 0;
    for (int j = 1; j <= n; j++) ans = max(ans, DP[m][j]);

    cout << ans;
    return 0;
}
