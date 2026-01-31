## 題目
https://zerojudge.tw/ShowProblem?problemid=b967

## 思路
這題先把血緣關係建成一顆binary tree，之後查找parent == -1的點作為根，並用開始用根來做DFS，不斷用best1、best2來做深度的更新
