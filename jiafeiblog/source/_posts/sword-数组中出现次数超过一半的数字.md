---
title: 数组中出现次数超过一半的数字
categories:
  - 剑指offer
tags:
  - 二分查找
date: 2019-12-26 23:12:31
---

## 题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

### 思路分析
- 解法1：利用题目特点，数字数量超过一半，则该数字一定是该数组的中位数，改造二分查找解决
- 解法2：变遍历变求解，因为答案的那个数字的总数大于剩下的数字的总和，
    所以遍历一遍，剩下的那个数字就是答案】
```cpp
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size() == 0) {
            return 0;
        }
        int res = numbers[0];// 记录当前中位数的可能值
        int times = 1;// 统计当前值的有效次数
        // 寻找目标
        for (int i  = 0; i < numbers.size();++i) {
            if (times <= 0) {
                res = numbers[i];
                times = 1;
            } else if (res == numbers[i]) {
                ++times;
            } else {
                times--;
            }
        }
        // 出现数量验证
        times = 0;
        for (int  i = 0; i < numbers.size();++i) {
            if (numbers[i] == res) {
                times++;
            }
        }
        if (times*2 <= numbers.size()) {
            return 0;
        }
        return res;
    }
    // 解法2
    int MoreThanHalfNum_Solution1(vector<int> numbers) {
        if (numbers.size() == 0) {
            return 0;
        }

        int num = numbers[0];
        int times = 1;
        for (int i = 1; i < numbers.size();++i) {
            if (numbers[i] == num){
                times++;
            } else if (times == 0){
                num = numbers[i];
                times = 1;
            } else {
                times--;
            }
        }
        // 出现数量验证
        times = 0;
        for (int  i = 0; i < numbers.size();++i) {
            if (numbers[i] == res) {
                times++;
            }
        }
        if (times*2 <= numbers.size()) {
            return 0;
        }
        return num;
    }
};
```