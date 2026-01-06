### VLA

- Header File

    `NO`

- Common Operations

Announcement(One-dimensional)｜ `int a[n];`

Announcement(Two-dimensional)｜ `int a[r][c];`

Value｜ `a[i];` *i -> index

- Features

  1. Easy
  2. This is illegal in C++ (Maybe will CE)
  3. Can use `int` or `string`

---

### Vector

- Header File

   `#include <vector>`

- Common Operations

Anncouncement(One-dimensional)｜ `vector<int> v(size, default value);` *size and default value can neglect

Anncouncement(Two-dimensional)｜ `vector<vector<int>> v(size, default value);` *size and default value can neglect

Anncouncement(Pair) ｜ `vector<pair<int, int>> v(size, default value);` *size and default value can neglect

Input｜ `v.push_bacK(x);`

Input｜ `v.emplace_back(x);` (Fast than `v.push_back(x);`)

Clear｜ `v.clear();`

Size｜ `v.size();`

Empty｜ `v.empty();`

Value｜ `v[i];` *i -> index

- Features

  1. Can change array length
  2. Only pop push at the end
  3. Save space
  4. Inefficient

---
 
### Queue

- Header File

   `#include <queue>`

- Common Operations

Anncouncement｜ `queue<int> q;`

Input｜ `q.push(x);`

Value｜ `q.front();`

Remove｜ `q.pop();`

Empty｜ `q.empty();`

Size｜ `q.size();`

- Features

  1. First in first out
  2. Always use in BFS

### Stack

- Header File

     `#include <stack>`

- Common Operations

Anncouncement｜ `stack<int> stk;`

Input｜ `stk.push(x);`

Value｜ `stk.top();`

Remove｜ `stk.pop();`

Empty｜ `stk.empty();`

Size｜ `stk.size();`

- Features

    1. Last in first out
    2. Normally, we wouldn't use `recursion + vector` instead.
