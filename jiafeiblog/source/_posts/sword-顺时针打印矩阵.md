---
title: 顺时针打印矩阵
categories:
  - 剑指offer
tags:
  - 矩阵
date: 2019-12-26 23:12:31
---

## 题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

### 解题思路
- 问题具体化，仔细分析可能的情形及其处理方案

```cpp

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        // 矩阵不一定是正方形
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0,j = 0;
        int circle = ((row > col?col:row)-1)/2+1;
        vector<int> res;
        res.clear();
        for (int k = 0; k <= circle; ++k){
            if (res.size() < row * col)
                for (int i = k;i < col - k;++i){
                    res.push_back(matrix[k][i]);
                }
            if (res.size() < row * col) {
                for (int j = k + 1;j < row - k; ++j){
                    res.push_back(matrix[j][col - k - 1]);
                }
            }
            if (res.size() < row * col)
                for (int i = col - k - 2;i >= k; --i){
                    res.push_back(matrix[row - k - 1][i]);
                }
            if (res.size() < row * col)
                for (int j = row - k - 2;j > k; --j){
                    res.push_back(matrix[j][k]);
                }
        }
        return res;
    }
};
```