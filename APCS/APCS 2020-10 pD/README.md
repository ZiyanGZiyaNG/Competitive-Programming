解這題無妨就是用線段數或BIT去砸(基本上以就這樣兩種，其他都要到 $O(n ^ 2)$ )，那這邊我選擇用BIT去砸
那既然要用到BIT也不妨來學一下BIT


- Binary Indexed Tree(BIT)又稱Fenwick Tree
是用來解決動態前綴和問題的

那要會實作最先要會的是 $lowbit$ ， $lowbit(x)$ 是「x 的二進位表示中，最低位的那個 1 所代表的數值」

可以直接用 `x & -x`解掉

那這樣幹嘛呢? 這就是為了要儲存用 $bit[i] = (i - lowbit(i) + 1, i)$ 的全部數

