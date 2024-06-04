---
title: 从上往下打印二叉树
categories:
  - 算法题集
tags:
  - BTree
date: 2019-12-26 23:06:07
---
## 层序打印二叉树，每一层从左往右打印
- 层序遍历，用辅助队列
- 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
```c++
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    // 层序遍历，用辅助队列
    // 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ans;
        // 辅助队列
        queue<TreeNode*> queue_tree;
        // 特殊情况处理
        if (root == nullptr) {
            return ans;
        } 
        // 层序遍历
        queue_tree.push(root);
        while(!queue_tree.empty()){
            // 获取数据，存入结果
            TreeNode * node = nullptr;
            node = queue_tree.front();
            queue_tree.pop();// 将一遍历的节点出栈
            ans.push_back(node->val);
            // 左右节点入队
            if (node->left != nullptr) {
                queue_tree.push(node->left);
            }
            if (node->right != nullptr) {
                queue_tree.push(node->right);
            }
        }
        return ans;
        
    }
};

```
