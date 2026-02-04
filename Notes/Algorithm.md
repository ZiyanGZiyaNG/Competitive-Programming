# 演算法 Algorithm

本講義以 **競賽程式設計（大學程式設計先修檢定／大學程式能力檢定／學科能力競賽／大學演算法、資料結構）** 為導向，  
系統性介紹常見演算法的 **原理、使用時機、複雜度等**。

<img width="480" height="270" alt="image" src="https://github.com/user-attachments/assets/33c58b57-63ff-40e8-8ef1-80ddd2e74d56" />


---

## 目錄

1.[簡述演算法](https://github.com/ZiyanGZiyaNG/Competitive-Programming/blob/main/Notes/Algorithm.md#1%E7%B0%A1%E8%BF%B0%E6%BC%94%E7%AE%97%E6%B3%95)

2.[複雜度](https://github.com/ZiyanGZiyaNG/Competitive-Programming/blob/main/Notes/Algorithm.md#2%E8%A4%87%E9%9B%9C%E5%BA%A6-complexity)

---

## 1.簡述演算法

### 為什麼需要演算法?
在競程中往往會有限制秒數，而在大部分時間暴力解是不會過的所以我們需要用演算法來壓縮解決問題的時間

---


## 2.複雜度 Complexity

### 1.複雜度
複雜度是用來估算這個程式的美醜，我們 **通常形容一個有好的複雜度的程式稱為美麗** (對!競程選手都這樣的)。那複雜度有兩種型態一種是時間複雜度(Time complexity)，另一種是空間複雜度(Space complexity)，那通常俗稱的複雜度是在指時間複雜度。

### 2.複雜度的表示
現在大多使用的 $big O$ (可以念`big o`或`big of o`抑或者`O`)來表示複雜度，那在 **複雜度的紀錄我們只會記錄最高次方** 像 $n ^ 3 + 3n ^ 2$，這樣只會記錄 $O(n ^ 3)$  
並且我們口中說的複雜度都是在說 $worst case$ ，畢竟討論 $best case$ 根本沒意義

### 3.常見複雜度
以下會解紹幾種常見的複雜度

 - $O(1)$ 常數時間，`if`、`cin`、`cout`、陣列讀取
 - $O(n)$ 線性時間，簡易的陣列查找
 - $O(logn)$ 對數時間，二分搜尋

### 4.複雜度的估算
在比賽中我們會看到題目要求的時間像

<img width="249" height="436" alt="Screenshot 2026-02-04 at 16 06 54" src="https://github.com/user-attachments/assets/1e54ad62-479c-48d8-b140-4c4a743be761" />

必須要在時間內跑完不然是不會AC的只會拿到TLE  
那我就先得估算會不會跑太久，通常我們會以1秒可以跑1e8作為估算，當然這個也會應為OJ的伺服器效能而產生影響  
所以如果一個程式的複雜度是 $O(n) 0 <= n <= 1000000$ 限制秒數為一秒，這樣你可以放心不會拿到TLE
但如果是 $O(nm) 0 <= n、m <= 1000000$，這樣的話就不一定了喔

---

## 3.排序演算法 (Sorting)

### 1.STL
在`#include <algorithm>`這個標頭檔中有提供sort函數可以直接使用基本上是最常用的排序方式  
在時間複雜度的部分為 $O(nlogn)$ ，採用的是混合式的排序方法在深度淺的時候使用Quick Sort在深度過深後會改成使用Heap Sort  
P.S. 在對vector進行sort要使用迭代器  

```cpp
// vector
vector<int> v;
sort(v.begin(). v.end());

// VLA
int a[n[;
sort(a, a + n);
```


### 2.Bubble Sort
最熟悉的排序演算法，因為像泡泡一直互換而得名  
用從小掃到大，如果左邊大於右邊，進行交換，這樣反覆掃描直到不用交換  
時間複雜度的部分為 $O(n ^ 2)$ 是因為需要反覆搜尋

```cpp
int a[n];
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n - 1; j++)
	{
		if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
	}
}
```

## 4.搜尋演算法 (Seartch)

### 1.暴力搜尋、線性搜尋 (Brute Force)
暴力搜人如其名非常暴力，因為是依陣列的大小從小搜到大所以又稱線性搜尋
複雜度為 $O(n)$

```cpp
int a[n];
int t;
bool find = false;
for (int i = 0; i < n; i++)
{
 if (a[i] = t) find = true;
}
```

### 2.二分搜尋 (Binary Seartch)
透過一半再一半的方法，用中間值來判斷下一步的區間變化。
如果大於中間值區間往右，反之往左
複雜度為 $O(logn)$

```cpp
int a[n];
int t;
bool find = false;
int l = 0, r = n - 1;
while (l < r)
{
	int mid = l + (r - l) / 2 + 1;
	if (a[mid] == t) 
	{
		find = true;
		break;
	}
	if (a[mid] > t) r = mid - 1;
	else l = mid + 1;
}
```


### 3.深度搜尋演算法 (Deepth-First Seartch, DFS)
一直往下搜尋直到搜尋到最底部再返回走別條分支，可用於 **樹** 、 **二維圖** 、 **字串**  
複雜度為 $O(nm)$ 但會因為剪枝的關係而產生變化，所以複雜度不一定

```cpp
int a[50][50];
int t; // target
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[50][50] = {false};
bool find = false;
void dfs(int x, int y)
{
	vis[x][y] = true;
	if (a[x][y] == t) 
	{
		find = true;
		return;
	}
	
	for (int d = 0; d < 4; d++)
	{
		int sx = x + dx[d];
		int sy = y + dy[d];
		if (sx >= 50 or sx < 0 or sy >= 50 or sy < 0) continue;
		if (vis[sx][sy]) continue;
		dfs(sx, sy);
	}
}
```

- 剪枝
一種DFS的技巧，目的是要讓DFS不去跑沒必要的程式，提早把程式完成  
這不僅僅可以預防TLE，還對滿腦子都是優化的競程選手十分友好
繼續使用上面的例子在做剪枝的舉例

```cpp
int a[50][50];
int t; // target
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[50][50] = {false};
bool find = false;
void dfs(int x, int y)
{
 if (find) return;
	vis[x][y] = true;
	if (a[x][y] == t) 
	{
		find = true;
		return;
	}
	
	for (int d = 0; d < 4; d++)
	{
		int sx = x + dx[d];
		int sy = y + dy[d];
		if (sx >= 50 or sx < 0 or sy >= 50 or sy < 0) continue;
		if (vis[sx][sy]) continue;
		dfs(sx, sy);
	}
}
```

### 4.廣度優先搜尋演算法 (Breeth-First Seartch, BFS)
跟DFS相反的一種演算法，一種是一路搜尋到最底部，一種是慢慢往外擴  
BFS會探索的區域會比DFS多出很多  
複雜度一樣為 $O(nm)$ ，但不會像DFS有剪枝改變複雜度

```cpp
int a[50][50];
int t; // target
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[50][50] = {false};
bool find = false;
void bfs(int sx, int sy) // sx = 0, sy = 0
{
	queue<pair<int, int>> q;
	q.push({sx, sy});
	vis[sx][sy] = true;
	
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;
		if (a[x][y] == t) find = true;
		if (find) return;
		for (int d = 0; d < 4; d++)
		{
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (xx >= 50 or xx < 0 or yy >= 50 or yy < 0) continue;
			if (vis[xx][yy]) continue;
			vis[xx][yy] = true;
			q.push({xx, yy});
		}
	}
}
```

---

## 4.動態規劃 (Dynamic Programming, DP)
動態規劃不能說是一種演算法，只能說他是一種演算法的精神，靠個前一項的數據來改變  
DP最重要的是轉移式 $dp[i] = dp[i - 1] + 10$ (我隨便舉例的，不可能出這樣)  

這邊我將用一個簡單的例子來展示DP的魅力  
這題是經典的青蛙問題  
題目｜[Atcoder dp_a Frog - 1](https://atcoder.jp/contests/dp/tasks/dp_a)

題目概述｜一隻青蛙可以一次跳一格或者兩格石頭，然而跳石頭是要付出代價的，代價是 $abs(h[i] - h[j])$ ，我們要找出最小的代價

題解｜走到第一顆石頭只有一種方法可以到所以只能dp[1] = abs(h[1] - h[0])  
但走到其他石頭就不是這樣了可以有兩種方法可以走到，可以一次走兩步或者走一步  
因為我們希望有著最少的代價，那根據貪心法的定理我們可以知道每步都走最少那麼整題都將是最少。
德證我們只需要選擇dp最小代價的就好了  
因此dp轉移式為 $dp[i] = min((dp[i - 1] + abs(h[i] - h[i - 1])), (dp[i - 2] + abs(h[i] - h[i - 2])))$
```cpp
#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int h[n];
	for (int i = 0; i < n; i++) cin >> h[i];
	
	int dp[n];
	dp[0] = 0;
	dp[1] = abs(h[1] - h[0]);
	
	for (int i = 2; i < n; i++)
	{
		int d = dp[i - 2] + abs(h[i] - h[i - 2]);
		int p = dp[i - 1] + abs(h[i] - h[i - 1]);
		
		dp[i] = min(d, p);
	}
	cout << dp[n - 1];
}
```
