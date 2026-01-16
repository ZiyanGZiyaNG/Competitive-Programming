### IF YOU WANT YOUR ALGORITHM ABILITY BECOME VERY STRONG I SUGGEST YOU GO TO PRATICE IN LEETCODE
[LeetCode](https://leetcode.com/problemset/)



## Search Algorithm

### Liner - Search(Sequential Search)

- Features
  1. Intuitive
  2. No sorting required
  3. Brute Force
 
- Efficiency

| Case    | Time Complexity |
|---------|:-----------------: |
| Best    | $O(1)$          |
| Average | $O(n)$          |
| Worst   | $O(n)$          |


- Code

```cpp
int linear(int a[], int n, int t)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == t)
        {
            return i;  
        }
    }
    return -1;    
}
```

---

### Binary Search 

- Features
  1. Fast
  2. Divide
  3. Need Sort
 
- Efficiency

| Case    | Time Complexity |
|---------|:-----------------: |
| Best    | $O(1)$          |
| Average | $O(log(n))$          |
| Worst   | $O(log(n))$          |

- Code

```cpp
int binary(int n, int a[], int t)
{
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int now = left + (right - left) / 2;

        if (a[now] == t)
        {
            return now;        
        }
        else if (a[now] > t)
        {
            right = now - 1;  
        }
        else
        {
            left = now + 1;    
        }
    }

    return -1;               
}
```

--- 


### Breadth-First Search

- Features
  1. Can in Binary Tree and Graph
  2. Use lots of memorize
 
- Efficiency

## Sort Algorithm

| Case    | Time Complexity |
|---------|:-----------------: |
| Best    | $O(1)$          |
| Average | $O(V + E) or O(m * n)$          |
| Worst   | $O(V + E) or O(m * n)$          |


- Code

```cpp
// <global>
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[1e9][1e9];
int mp[1e9][1e9];
// </global>

bool bfs(int sx, int sy, int gx, int gy)
{
	memset(vis, 0, sizeof(vis)); // #include <cstring>
	queue<pair<int, int>> q; // #include <queue>
	q.push({sx, sy});
	vis[sx][sy] = true;
	
	while (!q.empty())
	{
		if (mp[nx][ny] == mp[gx][gy]) return true;
		auto cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;
		
		for (int d = 0; d < 4; d++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			
			if (vis[nx][ny]) continue;
			if (nx >= n or nx < 0 or ny >= m or ny < 0) continue;
			
			vis[nx][ny] = true;
			q.push({nx, ny});
		}
	}
retrun false;
}
```

### STL

- Features
  1. Easy
  2. Need `#include <algorithm>`
 
- Efficiency

| Case    | Time Complexity |
|---------|:-----------------: |
| Best    | $O(log(n))$          |
| Average | $O(log(n))$          |
| Worst   | $O(log(n))$          |

- Code

```cpp
// VLA
int a[n];
sort(a, a + n);

// Vector
vector<int> a(n);
sort(a.begin(), a.end(();
```

---


### Bubble Sort

- Features
  1. Stable Sorting
 
- Efficiency

| Case    | Time Complexity |
|---------|:-----------------: |
| Best    | $O(n)$          |
| Average | $O(n ^ 2)$          |
| Worst   | $O(n ^ 2)$          |

- Code

```cpp
void bubble(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool s = false;
        for (int j = 1; j < n - i; j++)
        {
            if (a[j - 1] > a[j])
            {
                swap(a[j - 1], a[j]);
                s = true;
            }
        }
        if (!s) break; 
    }
}
```

---












<div align="center">Written by ZiyanGZiyaNG in 2026</div>
