---
title: 数组的逆序对
categories:
  - 剑指offer
tags:
  - 线性代数
date: 2019-12-26 23:12:31
---

## 题目描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
输入描述:
题目保证输入的数组中没有的相同的数字

数据范围：

	对于%50的数据,size<=10^4

	对于%75的数据,size<=10^5

	对于%100的数据,size<=2*10^5

示例1
输入

> 1,2,3,4,5,6,7,0
输出

> 7

### 思路
- 先弄懂归并排序再来看，OK
- 由于逆序对与归并排序中的。递归实现，先递归，后回溯排序
```cpp
class Solution {
public:
    /*
        归并排序思想
    */
    long long inversePairsCore(vector<int> &data,vector<int> &copy,int start,int end) {
        // 递归结束
        if (start >= end) {
            copy[start] = data[start];
            return 0;
        }
        int half = (end - start) / 2; // 取扫描数组段的数的一半，递归

        // 二分递归，copy与data互换位置
        long long left = inversePairsCore(copy, data, start, start + half);
        long long right = inversePairsCore(copy, data, start + half + 1, end);

        // 这一部分是回溯处理

        // 左半段游标
        int i = start + half;
        // 右半段游标
        int j = end;

        // 统计逆序数
        int indexCopy = end;
        long long count = 0;
        while (i >= start && j >= start + half + 1) {
            if (data[i] > data[j]) {            // 存在一个逆序对
                copy[indexCopy--] = data[i--];  // 复制i处的数
                count += j - start - half;      // 统计逆序数,因为数组是有序的。好好理解
            } else {                            // 否则，
                copy[indexCopy--] = data[j--];  // 复制j处的数
            }
        }

        // 复制i以前的数字
        for (;i >= start;i--) {
            copy[indexCopy--] = data[i];
        }
        // 复制j以前的数字
        for (;j >= start + half + 1;j--) {
            copy[indexCopy--] = data[j];
        }

        return (left + right + count);
    }

    int InversePairs(vector<int> data) {
        // 非法检查
        if (data.size() <= 0) {
            return 0;
        }
        
        // 复制一份
        vector<int> copy;
        for (int i = 0;i < data.size();++i) {
            copy.push_back(data[i]);
        }
        
        long long count = inversePairsCore(data,copy,0,data.size() -1);
        
        return count%1000000007;
    }
};
```