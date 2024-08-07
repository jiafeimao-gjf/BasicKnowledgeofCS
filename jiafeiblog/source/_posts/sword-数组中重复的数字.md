---
title: 数组中重复的数字
categories:
  - 剑指offer
tags:
  - 数组
date: 2019-12-26 23:12:31
---

## 题目描述
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。

### 解题思路
- 哈希思想，存储和查找

```cpp
class Solution {
public:

    bool duplicate(int numbers[], int length, int* duplication) {
        // 创建数组
        int *count = new int[length];
        for (int i = 0;i < length;++i) { // 初始化
            count[i] = 0;
        }
        // 统计
        for (int i = 0; i < length;++i) {
            count[numbers[i]]++;
        }
        // 招第一个出现两次的
        for (int i = 0; i < length;++i) {
            if (count[numbers[i]] == 2) {
                *duplication = numbers[i];
                return true; // 存在
            }
        }
        delete[] count; // 删除空间
        return false; // 不存在
    }
};
```