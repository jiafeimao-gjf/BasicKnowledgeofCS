---
title: 对称的二叉树
categories:
  - 剑指offer
tags:
  - BTree
date: 2019-12-26 23:12:31
---

## 题目描述
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
## 思路分析
- 中序遍历的细节考察，即中序遍历中，两个值的对应节点有哪些关系？
- 中序遍历：左-根-右
- 一共有三种情况：
    - 1、有右子树，进一步找最左节点
    - 2、没有右子树，本身是左子树
    - 3、没有右子树，本身是右子树,且父节点是祖父节点的右子树
```cpp
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next; //指向父节点的指针
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        // 非法处理
        if (pNode == NULL){
            return NULL;
        }
        TreeLinkNode* pNext = NULL;
        if (pNode->right != NULL){// 当前节点的右子树不为空
            TreeLinkNode *rNode = pNode->right;
            while(rNode->left != NULL){// 找右子树的最左孙子节点
                rNode = rNode->left;
            }
            pNext = rNode;
        }else if(pNode->next != NULL){// 下一个节点不为空
            // 当前节点的不是根节点的左子树最右子节点
            if (pNode->next->left == pNode){
                pNext = pNode->next;
            }else { // 查找根节点，好好理解一下。只有祖先节点的父节点为空
                TreeLinkNode *pCurrent = pNode;
                TreeLinkNode *pParent = pNode->next;
                // 一直递归到父节点为空或者非右子树节点 
                while(pParent != NULL && pParent->right == pCurrent){
                    pCurrent = pParent;
                    pParent = pParent->next;
                }
                pNext = pParent;
            }
        }
        return pNext;
    }
};
```