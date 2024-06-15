---
title: 按行打印二叉树
categories:
  - 剑指offer
tags:
  - BTree
date: 2019-12-23 23:06:29
---
## 题目描述
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。

## 思路分析
- 层序遍历，修改一下存储每一层的数据
- 辅助变量的使用，
    - 当前层的节点数、
    - 下一层的节点数，
    - 当前层输出存储
    - 队列存储每一层的子节点，先左后右

```cpp
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
  // 队列实现层序遍历
  vector<vector<int> > Print(TreeNode* pRoot) {
      vector<vector<int>> res;
      // 非法判断
      if (pRoot == nullptr) {
          return res;
      }
      // 辅助变量：队列
      queue<TreeNode*> level;
      level.push(pRoot);
      int nextLevel = 0;// 统计某一层的节点数
      int toBePrinted = 1;// 层的节点数，第一层只有一个节点
      vector<int> levelRes;
      // 循环遍历
      while (!level.empty()) {
          // 输出保存
          TreeNode* p = level.front();
          levelRes.push_back(p->val);
          
          // 节点入队
          if (p->left != nullptr) {
              level.push(p->left);
              ++nextLevel;
          }
          
          if (p->right != nullptr) {
              level.push(p->right);
              ++nextLevel;
          }
          // 节点出队
          level.pop();// 队首节点出队
          --toBePrinted;// 当层节点数量剪一
          // 层完结
          if (toBePrinted == 0) {
              // 更新为层节点数量
              toBePrinted = nextLevel;
              //更新下一层的节点数量
              nextLevel = 0;
              
              // 将当层数据保存
              res.push_back(levelRes);
              levelRes.clear();//清除已保存的数据
          }
          
      }
      return res;
  }
};
```