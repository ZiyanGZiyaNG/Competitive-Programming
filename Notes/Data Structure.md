# 資料結構 Data Structures

本講義以 **競賽程式設計（大學程式設計先修檢定／大學程式能力檢定／學科能力競賽／大學演算法、資料結構）** 為導向，  
系統性介紹常見資料結構的 **定義、特性、時間複雜度與使用時機**。

<img width="320" height="180" alt="image" src="https://github.com/user-attachments/assets/8cc490db-bac3-47ae-aaf5-5ce73e8456b1" />

---

## 目錄

1. [資料結構概論](https://github.com/ZiyanGZiyaNG/Competitive-Programming/blob/main/Notes/Data%20Structure.md#1-%E8%B3%87%E6%96%99%E7%B5%90%E6%A7%8B%E6%A6%82%E8%AB%96)
2. [Array & VLA](https://github.com/ZiyanGZiyaNG/Competitive-Programming/blob/main/Notes/Data%20Structure.md#2-array--vla)  
3. [Vector](https://github.com/ZiyanGZiyaNG/Competitive-Programming/blob/main/Notes/Data%20Structure.md#3-vector-%E5%8B%95%E6%85%8B%E9%99%A3%E5%88%97)
4. [Queue](https://github.com/ZiyanGZiyaNG/Competitive-Programming/blob/main/Notes/Data%20Structure.md#4-queue-%E4%BD%87%E5%88%97)
5. [Stack](https://github.com/ZiyanGZiyaNG/Competitive-Programming/blob/main/Notes/Data%20Structure.md#5stack-%E5%A0%86%E7%96%8A)
6. [Deque](https://github.com/ZiyanGZiyaNG/Competitive-Programming/blob/main/Notes/Data%20Structure.md#6deque-%E9%9B%99%E5%90%91%E4%BD%87%E5%88%97)  
7. Set & Multiset  
8. Map  
9. Unordered Set & Unordered Map  
10. Linked List  
11. Priority Queue  
12. Disjoint Set（Union-Find）

---

## 1. 資料結構概論

### What is 資料結構？

資料結構（Data Structure）是用來  
**組織、儲存、管理與存取資料**的一種方式。

透過合適的資料結構，可以讓資料在  
查詢、插入、刪除、更新等操作上更有效率，  
並使演算法設計更加清楚、可控。

### 為什麼資料結構很重要？

- **直接影響時間複雜度（Big-O）**
- **是演算法設計的基礎**
- **競賽中常因資料結構選錯而 TLE / WA**
- **功能相同 ≠ 效率相同**

---

## 2. Array & VLA

### Array（固定長度陣列）

#### 特性

- 記憶體連續配置
- 隨機存取速度快
- 長度在宣告後不可改變
- 是多數資料結構的底層基礎


#### 語法

**一維陣列**｜

```int a[10];```

```int a[5] = {1, 2, 3, 4, 5};```

**二維陣列**｜

```int b[3][4];```

```int b[2][3] = {{1,2,3},{4,5,6}};```


**索引存取**｜

```a[i];```

```b[i][j];```

---

### VLA

#### 特點

- 基本跟Array一樣，只是長度放變數
- 為`c99`的語法，在C++中是不合法的，但某些編譯器是合法可用的


#### 語法

**一維陣列**｜

```int a[10];```

```int a[5] = {1, 2, 3, 4, 5};```

**二維陣列**｜

```int b[3][4];```

```int b[2][3] = {{1,2,3},{4,5,6}};```


**索引存取**｜

```a[i];```

```b[i][j];```


---

## 3. Vector (動態陣列)

### 特點

- 可以動態調整陣列大小
- 標準容器(STL)
- VLA的接班人
- 需要標頭檔 `#include <vector>`


### 語法

**宣告**｜ 
```vector<int> v(長度, 初始值);```


**加入元素**｜

```v.push_back(x);```

```v.emplace_back(x) // 較快;```


**刪除尾端元素**｜
```v.pop_back();```

**索引存取**｜
```v[i];```


**重設大小**｜
```v.resize();```


**取得大小**｜
```v.size();```


**清空 Vector**｜
```v.clear();```


## 4. Queue (佇列)

### 特點

- 先進先出(First In First Out)
- 像排隊
- 在BFS中會用到
- 需要標頭檔`#include <queue>`


### 語法
**宣告**|
```queue<int> q;```

**插入**|
```q.push(x);```

**刪除**|
```q.pop();```

**取值**|
```q.front();```

**取得大小**｜
```q.size();```

**清空**｜
```q.clear();```

## 5.Stack (堆疊)

### 特點

- 後進先出(Last In First Out)
- 像書本堆疊
- 有些人在DFS會用到(但筆者主要用)
- 需要標頭檔`#include <stack>`
- 在競程中其實不太喜歡用這個，大部分人反而會用`vector`來取代

### 語法

**宣告**|
```stack<int> stk;```

**插入**|
```stk.push(x);```

**取值**|
```stk.top();```

**刪除**|
```stk.pop();```

**取得大小**｜
```stk.size();```

**清空**｜
```stk.clear();```

## 6.Deque (雙向佇列)

### 特點
- Double-ended queue
- 相較Queue可兩端插入
- 需要標頭檔`#include <deque>`
- 基本上用不太到
<img width="320" height="180" alt="image" src="https://github.com/user-attachments/assets/74340045-d1e8-4a9a-a163-3acc981cdda9" />


### 語法

**宣告**|
```deque<int> de;```

**插入到尾端**|
```de.push_back(x);```

**插入到頭端**|
```de.push_front(x);```

**刪除尾端**|
```de.pop_back();```

**刪除頭端**|
```de.pop_front();```
