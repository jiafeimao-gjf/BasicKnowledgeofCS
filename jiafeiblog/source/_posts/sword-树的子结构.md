---
title: 树的子结构
categories:
  - 剑指offer
tags:
  - BTree
date: 2019-12-26 23:12:31
---

## 题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

### 思路
- 递归枚举，枚举主树的每个节点，与目标树的根节点匹配，一旦匹配上就完成
- 递归匹配，对两个根节点，同步匹配，保证每个节点的值都一样，一旦不同返回`false`
- 这道题将递归应用到了极致

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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        // 特殊情况判断
        if (pRoot1 == nullptr || pRoot2 == nullptr) return false;
        bool res = false;
        // 当前节点满足递归匹配，注意结点点的值的类型，判断是否可以直接比较
        if (pRoot1->val == pRoot2->val) res = isSubTree(pRoot1,pRoot2);
        // 递归匹配左子树
        if (!res) res = HasSubtree(pRoot1->left,pRoot2);
        // 递归匹配右子树
        if (!res) res = HasSubtree(pRoot1->right,pRoot2);
        return res;
    }
    
    bool isSubTree(TreeNode* pRoot1,TreeNode* pRoot2){
        if (pRoot2 == nullptr) return true;// 到达B树叶子节点
        if (pRoot1 == nullptr) return false;// 到达A树叶子节点
        bool res = true;
        if(pRoot1->val != pRoot2->val) res = false;// 当前节点不满足
        // 满足递归左子树
        if(res) res = isSubTree(pRoot1->left,pRoot2->left);
        // 满足，则递归右子树
        if(res) res = isSubTree(pRoot1->right,pRoot2->right);
        return res;
    }
};
```