---
title: 求1～n的和
categories:
  - 剑指offer
tags:
  - 求和
date: 2019-12-26 23:12:31
---

## 题目描述
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

### 思路
- 等差数列求和了解一下

```cpp
class Solution {
public:
    int Sum_Solution(int n) {
        return (1+n)*n/2;
    }
};
```

