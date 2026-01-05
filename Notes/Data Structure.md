## VLA (變長度陣列)

- 常用操作｜

| 操作類別 | 語法 | 功能說明 | 時間複雜度 |
|---|---|---|---|
| 宣告（1D） | `int a[n];` | 建立長度 n | O(1) |
| 宣告（2D） | `int a[r][c];` | 建立 r×c | O(1) |
| 空間 | `int a[n];` | 佔用 n 個元素的記憶體 | O(n) |
| 空間（2D） | `int a[r][c];` | 佔用 r·c 個元素的記憶體 | O(r·c) |
| 存取（1D） | `a[i]` | 存取第 i 個元素 | O(1) |
| 存取（2D） | `a[i][j]` | 存取第 (i,j) 個元素 | O(1) |

- 特點｜

  1. C++不合法的陣列用法，某些Online Judge會CE
  2. 真香!!




## Vector (動態陣列)
- 標頭檔｜

 `#include <vector>`

- 常用操作 ｜

| 操作類別 | 語法 | 功能說明 | 時間複雜度 |
|---|---|---|---|
| 宣告 | `vector<int> v;` | 建立空陣列 | O(1) |
| 指定長度 | `vector<int> v(n);` | 長度 n，元素預設 0 | O(n) |
| 指定長度與初值 | `vector<int> v(n, x);` | 長度 n，元素全為 x | O(n) |
| 尾端加入 | `v.push_back(x);` | 尾端新增 |  O(1) |
| 尾端就地建構 | `v.emplace_back(x);` | 尾端新增(較`v.push_back()`慢) |  O(1) |
| 尾端刪除 | `v.pop_back();` | 刪除尾端元素 | O(1) |
| 取尾端 | `v.back();` | 取得最後元素（不刪） | O(1) |
| 取大小 | `v.size();` | 元素數量 | O(1) |
| 判空 | `v.empty();` | 是否為空 | O(1) |
| 清空 | `v.clear();` | 清除所有元素 | O(n) |
| 存取 | `v[i]` | 存取第 i 個 | O(1) |
| 中間插入 | `v.insert(pos, x);` | 在 pos 前插入 x | O(n) |
| 中間刪除 | `v.erase(pos);` | 刪除 pos 位置元素 | O(n) |
| 刪除區間 | `v.erase(l, r);` | 刪除 [l, r) | O(n) |

- 特殊的用法

`vector<pair<int, int>> v;`  通常使用在二元資料

取值：`v[i].first`、`v[i].second`  
加入：`v.push_back({x, y});`

`vector<vector<int>> v;` 二維陣列


- 特點 ｜

  1. 可變長度（可一直尾端加入）
  2. C++唯一合法陣列
  3. 優質的效率
  4. 可以搭配STL 眼算法做使用
 

## Stack (堆疊)

- 標頭檔｜

`#include <stack>`

- 常用操作｜

| 操作類別 | 語法 | 功能說明 | 時間複雜度 |
|---|---|---|---|
| 宣告 | `stack<int> st;` | 建立空堆疊 | O(1) |
| 推入 | `st.push(x);` | 將 x 放到頂端 | O(1) |
| 彈出 | `st.pop();` | 移除頂端元素 | O(1) |
| 取頂端 | `st.top();` | 取得頂端元素 | O(1) |
| 取大小 | `st.size();` | 元素數量 | O(1) |
| 判空 | `st.empty();` | 是否為空 | O(1) |

- 特點｜
  1. LIFO:先進先出
  2. 不太會用到(至少我是這樣
 

## Queue (佇列)

- 標頭檔｜
`#include <queue>`

- 常用操作 ｜

| 操作類別 | 語法 | 功能說明 | 時間複雜度 |
|---|---|---|---|
| 宣告 | `queue<int> q;` | 建立空佇列 | O(1) |
| 推入 | `q.push(x);` | 將 x 放到尾端 | O(1) |
| 彈出 | `q.pop();` | 移除隊首元素（不回傳值） | O(1) |
| 取隊首 | `q.front();` | 取得隊首元素（不移除） | O(1) |
| 取隊尾 | `q.back();` | 取得隊尾元素（不移除） | O(1) |
| 取大小 | `q.size();` | 元素數量 | O(1) |
| 判空 | `q.empty();` | 是否為空 | O(1) |

- 特點｜
  1.FIFO:先進先出
  2.BFS常用


## set（有序集合）

- 標頭檔｜
`#include <set>`

- 常用操作｜

| 操作類別 | 語法 | 功能說明 | 時間複雜度 |
|---|---|---|---|
| 宣告 | `set<int> s;` | 建立空集合（不重複、會排序） | O(1) |
| 插入 | `s.insert(x);` | 插入 x（若已存在不變） | O(log n) |
| 刪除（值） | `s.erase(x);` | 刪除值 x（若存在） | O(log n) |
| 查找 | `s.find(x);` | 找 x，回傳 iterator | O(log n) |
| 是否存在 | `s.count(x);` | 存在回 1，不存在回 0 | O(log n) |
| 下界 | `s.lower_bound(x);` | 第一個 `>= x` 的位置 | O(log n) |
| 上界 | `s.upper_bound(x);` | 第一個 `> x` 的位置 | O(log n) |
| 取最小 | `*s.begin()` | 最小值 | O(1) |
| 取最大 | `*prev(s.end())` | 最大值 | O(1) |
| 取大小 | `s.size();` | 元素數量 | O(1) |
| 判空 | `s.empty();` | 是否為空 | O(1) |
| 清空 | `s.clear();` | 清除所有元素 | O(n) |

- 特點｜
  1. 自動排序、元素不重複（通常是平衡樹）
  2. 能找前驅/後繼（`lower_bound/upper_bound`），適合「動態有序」題
  3. 不支援用索引存取（沒有 `s[i]`）

---

## multiset（可重複的有序集合）

- 標頭檔｜
`#include <set>`

- 常用操作｜

| 操作類別 | 語法 | 功能說明 | 時間複雜度 |
|---|---|---|---|
| 宣告 | `multiset<int> ms;` | 建立空 multiset（可重複、會排序） | O(1) |
| 插入 | `ms.insert(x);` | 插入 x（可插入多次） | O(log n) |
| 查找一個 | `ms.find(x);` | 找到任一個 x 的位置 | O(log n) |
| 計數 | `ms.count(x);` | x 出現次數 | O(k + log n) |
| 刪除（全部 x） | `ms.erase(x);` | 刪掉所有值為 x 的元素 | O(k + log n) |
| 刪除（一個 x） | `ms.erase(ms.find(x));` | 只刪掉一個 x（需先確認存在） | O(log n) |
| 下界 | `ms.lower_bound(x);` | 第一個 `>= x` 的位置 | O(log n) |
| 上界 | `ms.upper_bound(x);` | 第一個 `> x` 的位置 | O(log n) |
| 取最小 | `*ms.begin()` | 最小值 | O(1) |
| 取最大 | `*prev(ms.end())` | 最大值 | O(1) |
| 取大小 | `ms.size();` | 元素數量 | O(1) |
| 判空 | `ms.empty();` | 是否為空 | O(1) |
| 清空 | `ms.clear();` | 清除所有元素 | O(n) |

- 特點｜
  1. 自動排序、允許重複
  2. **注意**：`ms.erase(x)` 會刪掉所有 x；要刪一個需用 iterator 版本

---

## map（有序映射 / key -> value）

- 標頭檔｜
`#include <map>`

- 常用操作｜

| 操作類別 | 語法 | 功能說明 | 時間複雜度 |
|---|---|---|---|
| 宣告 | `map<int,int> mp;` | 建立空 map（key 不重複、會排序） | O(1) |
| 指派/新增 | `mp[key] = val;` | 設定 key 的值（不存在會自動建立） | O(log n) |
| 讀取 | `mp[key]` | 取得 key 的值（不存在會建立並回傳預設值） | O(log n) |
| 插入（不覆蓋） | `mp.insert({k, v});` | 若 k 已存在則不插入 | O(log n) |
| 查找 | `mp.find(k);` | 找 key，回傳 iterator | O(log n) |
| 是否存在 | `mp.count(k);` | 存在回 1，不存在回 0 | O(log n) |
| 刪除 | `mp.erase(k);` | 刪除 key | O(log n) |
| 下界 | `mp.lower_bound(k);` | 第一個 key `>= k` 的位置 | O(log n) |
| 上界 | `mp.upper_bound(k);` | 第一個 key `> k` 的位置 | O(log n) |
| 取最小 key | `mp.begin()->first` | 最小 key | O(1) |
| 取最大 key | `prev(mp.end())->first` | 最大 key | O(1) |
| 取大小 | `mp.size();` | 鍵值對數量 | O(1) |
| 判空 | `mp.empty();` | 是否為空 | O(1) |
| 清空 | `mp.clear();` | 清除所有鍵值對 | O(n) |

- 特點｜
  1. key 會自動排序（平衡樹），適合需要「有序」或「範圍查詢」的 key
  2. **注意**：`mp[key]` 會「自動建立 key」，只想查有沒有請用 `find` 或 `count`



## unordered_map（雜湊映射 / key -> value，無序）

- 標頭檔｜
`#include <unordered_map>`

- 常用操作｜

| 操作類別 | 語法 | 功能說明 | 時間複雜度（平均） |
|---|---|---|---|
| 宣告 | `unordered_map<long long,int> um;` | 建立空 unordered_map（無序） | O(1) |
| 指派/新增 | `um[key] = val;` | 設定 key 的值（不存在會建立） | O(1) |
| 計數常用 | `um[key]++;` | key 次數 +1（不存在先建立為 0） | O(1) |
| 查找 | `um.find(key);` | 找 key，回傳 iterator | O(1) |
| 是否存在 | `um.count(key);` | 存在回 1，不存在回 0 | O(1) |
| 刪除 | `um.erase(key);` | 刪除 key | O(1) |
| 取大小 | `um.size();` | 鍵值對數量 | O(1) |
| 清空 | `um.clear();` | 清除所有鍵值對 | O(n) |

- 特點｜
  1. 平均很快（雜湊），但**不保證順序**
  2. 不支援 `lower_bound/upper_bound`（因為無序）
  3. `um[key]` 也會自動建立 key（和 map 一樣的陷阱）



## unordered_set（雜湊集合，無序）

- 標頭檔｜
`#include <unordered_set>`

- 常用操作｜

| 操作類別 | 語法 | 功能說明 | 時間複雜度（平均） |
|---|---|---|---|
| 宣告 | `unordered_set<int> us;` | 建立空 unordered_set（無序、不重複） | O(1) |
| 插入 | `us.insert(x);` | 插入 x（若已存在不變） | O(1) |
| 刪除 | `us.erase(x);` | 刪除 x（若存在） | O(1) |
| 查找 | `us.find(x);` | 找 x，回傳 iterator | O(1) |
| 是否存在 | `us.count(x);` | 存在回 1，不存在回 0 | O(1) |
| 取大小 | `us.size();` | 元素數量 | O(1) |
| 判空 | `us.empty();` | 是否為空 | O(1) |
| 清空 | `us.clear();` | 清除所有元素 | O(n) |

- 特點｜
  1. 平均很快，但無序
  2. 只適合「查存在/去重/計數」；需要排序或找最接近請用 `set`




## IO 優化
```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```
