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
