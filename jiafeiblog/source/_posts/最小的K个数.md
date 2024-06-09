---
title: 最小的k个数字
categories:
  - 算法题集
tags:
  - 数组
  - 排序
date: 2019-12-26 23:12:31
---

## 题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

### 解题思路
- 解法 1 ：在允许修改原来数组的元素位置时，可基于快速排序的二分函数，找到排在第K位的数字。
-  解法 2 ：不允许改变原数组，建立一个容量只有k个的容器，遍历一边原数组，对改容器进行更新，最后剩下来的，就是我们需要的最小的K个数字
```cpp
class Solution {
public:
    /*
        二分函数，随机选择一个数字，进行数组二分
    */
    int partition(vector<int> &input,int start, int end){
        int key = input[end];
        int index = start - 1;// 只记录小的数字的位置
        for (int i = start;i < end; ++i) {
            if (input[i] <= key) {
                ++index;
                if (index != i){// 将后面的小的数字前移
                    // 数字交换，基于数轴
                    input[index] = input[i] - input[index];
                    input[i] = input[i] - input[index];
                    input[index] = input[i] + input[index];
                }
            }
        }
        ++index;
        if (index != end) {
            // 数字交换。基于异或
            input[index] = input[end]^input[index];
            input[end] = input[end]^input[index];
            input[index] = input[end]^input[index];
        }
        
        return index;
    }
    // 基于快速排序的二分函数，找到排在第K位的数字。
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (input.size() <= 0 || k > input.size()) {
            return res;
        }
        int start = 0;
        int end = input.size() - 1;
        int index = partition(input,start,end);
        while(index != k - 1 && start < end) { // 找到前k个就行
            if (index <= k - 1) {
                start = index + 1;
                index = partition(input,start,end);
            } else {
                end = index - 1;
                index = partition(input,start,end);
            }
        }
        
        for (int i = 0;i < k;i++) {
            res.push_back(input[i]);
        }
        
        return res;
    }
};
```