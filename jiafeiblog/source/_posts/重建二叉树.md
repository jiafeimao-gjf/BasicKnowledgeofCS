---
title: 重建二叉树
categories:
  - 剑指offer
tags:
  - BTree
date: 2019-12-26 23:12:31
---

## 题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

## 思路
- 递归实现
- 利用前序遍历和中序遍历定位左右子树区间
- 利用具体的例子，确定递归建立左右子树的区间范围

```cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.size() != vin.size()){
            return NULL;
        }else{
            return rebuild(pre,0,pre.size()-1,vin,0,vin.size()-1);
        }
    }
    
    TreeNode* rebuild(vector<int> pre,int pl,int pr,vector<int> vin,int vl,int vr) {
        if (vl>vr && pl>pr) return NULL;
        int root = pre[pl];
        TreeNode* rootNode = new TreeNode(root);
        int i = 0;
        // 确定中序遍历中左右子树分割位置
        while(vin[i+vl]!=root && (i+vl) <= vr){
            ++i;
        }
        // 递归建左子树，左右区间很关键。pl+1~pl+i,vl~vl+i-1很关键
        rootNode->left = rebuild(pre,pl+1,pl+i,vin,vl,vl+i-1);
        // 递归建左子树，左右区间很关键。pl+i+1~pr,vl+i+1~vr很关键
        rootNode->right = rebuild(pre,pl+i+1,pr,vin,vl+i+1,vr);
        return rootNode;
    }
};
```