---
title: 斐波那契数列，求第n个数
categories:
  - 剑指offer
tags:
  - 斐波那契数列
date: 2019-12-26 23:12:31
---

## 题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39

### 循环实现 
- 时间辅助度 O(n)
- 空间复杂度 O(1)
```cpp
class Solution {
public:
    int Fibonacci(int n) {
        int f1 = 0;
        int f2 = 1;
        if (n == 0) return 0;
        if (n == 1) return 1;
        int fn;
        for (int i = 2; i <= n;i++){
            fn = f1 + f2;
            f1 = f2;
            f2 = fn;
        }
        return fn;
    }
};

```