---
title: 数组中只出现一次的两个数字
categories:
  - 剑指offer
tags:
  - 位运算
date: 2019-12-26 23:12:31
---

## 题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

### 思路分析
- 通过二进制实现，利用异或运算的特点，不同为1，相同为0
- 一个数字连续异或两个相同的数字，结果仍是这个数字本身
- 将所有数字异或，结果一定不为0，找出第一个1出现第几位，
- 表示为那两个只出现1次的数字异或的结果，
- 这一位中，这两个数字一个是1，另一个是0

```cpp
class Solution {
public:
    // 获取数字二进制中的第一个1的位置
    unsigned int FindFirstBitIs1(int num) {
        int indexBit = 0;
        while (((num & 1) == 0) && (indexBit < 8 * sizeof(int))) {
            num = num >> 1;
            ++indexBit;
        }
        return indexBit;
    }
    // 判断num的二进制的第indexBit位是不是1
    bool IsBit1(int num,unsigned int indexBit) {
        num = num >> indexBit;
        return (num & 1);
    }
    // 引用传值，可以不用返回
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        // 数据检查
        if (data.size() <= 1) {
            return;
        }
        
        // 将数组的所有数字异或
        int resOfOR = 0;
        for (int i = 0;i < data.size();++i) {
            resOfOR ^= data[i];
        }
        // 获取异或结果的第一个1，将数字分成两份
        int indexBit1 = FindFirstBitIs1(resOfOR);
        // 通过第一个1的位置，将原数组分成两波,然后异或运算，获取那两个数字
        *num1 = *num2 = 0;
        for (int i = 0; i < data.size();++i) {
            if (IsBit1(data[i],indexBit1)) { // 求num1
                *num1 ^= data[i];
            } 
            /* 
            else {
                *num2 ^= data[i];
            }*/
        }
        *num2 = *num1 ^ resOfOR;// 利用异或运算的特点，求num2
    }
};
```