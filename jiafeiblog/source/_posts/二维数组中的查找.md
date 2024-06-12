---
title: 二维数组中的查找
categories:
  - 剑指offer
tags:
  - 数组
date: 2019-12-26 23:12:31
---

## 题目描述
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
### 书上思路：返回缩小的方法每次一行或者一列
* 从右上方，当前值大于目标值，缩短一列，否则缩短一行
* 从左下方，当前值大于目标值，缩短一行，否则缩短一列

```cpp
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        bool flag = false;
        int r = array.size();// 获取行数
        int c = array[0].size();// 获取行的元素个数
        // 横纵查找，
        // i 为纵向，负责从小到大遍历
        // j 为横向，负责从大到小遍历
        for (int i = 0,j = c - 1;i < r && j >= 0;){
            if (array[i][j] == target){
                flag = true;
                break;
            }
            if (array[i][j] > target){ // 当前值大了
                j--; // 行缩
            }else { // 当前值小了
                i++; // 列缩 
            }
        }
        return flag;
    }
};

```