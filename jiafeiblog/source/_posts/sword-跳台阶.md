---
title: 跳台阶
categories:
  - 剑指offer
tags:
  - 斐波那契数列
date: 2019-12-26 23:12:31
---

## 题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

## 分析
- 原理就是斐波那契数列

```cpp
// 递归实现
class Solution {
public:
    int jumpFloor(int number) {
        if (number == 1) return 1;
        if (number == 2) return 2;
        return jumpFloor(number - 1) + jumpFloor(number - 2);
    }
};
```

## 变态版
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

```cpp
class Solution {
public:
    // 数学归纳法证明 有 2^(n-1)中情况
    int jumpFloorII(int number) {
        if (number == 0) return 0;
        int res = 1;
        for (int i = 1; i < number;i++){
            res *= 2;
        }
        return res;
    }
};

```