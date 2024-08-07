---
title: 矩阵中的路径
categories:
  - 剑指offer
tags:
  - 矩阵
  - 深度优先搜索
date: 2019-12-26 23:12:31
---

## 题目描述
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

### 思路
- 递归，深度优先遍历、回溯
- 

```cpp
class Solution {
public:
   
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        // 非法输入
        if (matrix == NULL || rows < 1 || cols < 1 || str == NULL){
            return false;
        }
        
        //辅助空间
        bool* visited = new bool[rows*cols];
        memset(visited,0,rows*cols);
        int pathLength = 0;
        // 遍历穷举
        for (int i = 0;i < rows;++i){
            for (int j = 0;j < cols; ++j){
                if (hasPathCore(matrix,rows,cols,i,j,pathLength,str,visited)){
                    return true;
                }
            }
        }
        // 删除辅助空间
        delete[] visited;
        return false;
    }

    // 子函数，判断是否有合法的路径，来满足条件
    bool hasPathCore(const char *matrix,int rows,int cols,int row,int col,int& pathLength,const char* str,bool* visited){
        // 遍历完毕
        if (str[pathLength] == '\0'){
            return true;
        }
        
        bool hasPath = false;
        if (row >= 0 && row < rows && col >= 0 && col < cols
           && matrix[row*cols + col] == str[pathLength]
           && !visited[row*cols + col]){// 满足条件
            ++pathLength; // 找到一个字符，长度++
            visited[row * cols + col] = true;
            // 遍历穷举
            hasPath = hasPathCore(matrix,rows,cols,row+1,col,pathLength,str,visited) 
                || hasPathCore(matrix,rows,cols,row-1,col,pathLength,str,visited) 
                || hasPathCore(matrix,rows,cols,row,col+1,pathLength,str,visited) 
                || hasPathCore(matrix,rows,cols,row,col-1,pathLength,str,visited);

            if (!hasPath){
                visited[row*cols + col] = false;
                --pathLength;
            }
        }

        return hasPath;
    }
};
```