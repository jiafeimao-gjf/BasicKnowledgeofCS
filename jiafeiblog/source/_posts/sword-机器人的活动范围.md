---
title: 机器人的活动范围
categories:
  - 剑指offer
tags:
  - 深度优先搜索
date: 2019-12-26 23:12:31
---

## 题目描述
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？

### 思路
- 递归、回溯、深度优先遍历 
```cpp
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if (threshold < 0 || rows < 0 || cols < 0) return 0;// 参数检查
        
        bool* visited = new bool[rows * cols];// 辅助访问记录数组
        memset(visited,false,rows * cols);
        
        int count = movingCountCore(threshold,rows,cols,0,0,visited);// 递归 & 回溯
        
        delete[] visited;// 删除空间
        
        return count;
    }
    
    int movingCountCore(int threshold, int rows,int cols,int row,int col,bool* visited){
        int count = 0;
        if (check(threshold,rows,cols,row,col,visited)){// 可以进入
            
            visited[row * cols + col] = true;// 标记为true
            
            // 递归调用，上下左右移动
            count = 1 + movingCountCore(threshold,rows,cols,row + 1,col,visited)
                + movingCountCore(threshold,rows,cols,row - 1,col,visited)
                + movingCountCore(threshold,rows,cols,row,col + 1,visited)
                + movingCountCore(threshold,rows,cols,row,col - 1,visited);
        }
        
        return count;
    }
    
    // 检查是否满足要求
    bool check(int threshold,int rows,int cols,int row,int col,bool* visited){
        if (row >= 0 && col >= 0 && row < rows && col < cols
            && getSum(row) + getSum(col) <= threshold 
            && !visited[row * cols + col]){
            return true;
        }
        return false;
    }
    //求各位之和
    int getSum(int num){
        int sum = 0;
        while(num >= 10){
            sum += num % 10;
            num /= 10;
        }
        sum += num;
        return sum;
    }
};
```