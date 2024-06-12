---
title: 二叉树的镜像
categories:
  - 剑指offer
tags:
  - BTree
date: 2019-12-26 23:12:31
---

## 题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:
二叉树的镜像定义：源二叉树 
```
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
```

### 思路分析
- 前序遍历
- 判断左右子树交换
```cpp
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
    void Mirror(TreeNode *pRoot) {
        if (pRoot == nullptr) {
            return;
        }
		// 交换左右子树
        TreeNode* temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
		// 递归左右子树
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};
```