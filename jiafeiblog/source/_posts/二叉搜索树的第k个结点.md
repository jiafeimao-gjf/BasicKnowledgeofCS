---
title: 二叉树的第k个节点
categories:
  - 算法题集
tags:
  - BTree
date: 2019-12-26 23:12:31
---

## 题目描述
给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。

### 思路分析
- 中序遍历，边遍历边计数

### Java 循环中实现，要回手写非递归算法
- 辅助指针 辅助栈，其他算法辅助变量
- 外循环，栈非空
    - 不断添加最左节点入栈
    - 回溯出栈，算法处理
    - 更新指针为最左子树的右子树
```Java
/*
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/

import java.util.*;
public class Solution {
    int count = 0;
    // 非递归中序遍历
    TreeNode KthNode(TreeNode pRoot, int k)
    {
        // 退出判断
        if(count > k || pRoot == null)
            return null;
        // 辅助指针
        TreeNode p = pRoot;
        // 辅助栈
        Stack<TreeNode> LDRStack = new Stack<TreeNode>();
        TreeNode kthNode = null;// 结果节点
        while(p != null || !LDRStack.isEmpty()){
            while(p != null){// 遍历到最左节点
                LDRStack.push(p);
                p = p.left;
            }
            TreeNode node = LDRStack.pop();
            // System.out.print(node.val+",");
            count++;// 计数
            if(count == k){ // 找到第k个节点
                kthNode = node;
                break;// 直接退出循环
            }
            p = node.right;// 回溯，遍历沿途的右分支
        }
        return kthNode;
    }

}
```

### C++版 递归实现
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
    int count = 0;
    // 递归中序遍历
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot){
                //递归左
                TreeNode *ret = KthNode(pRoot->left, k);
                // 返回值不为空，找到了第k大的节点
                if(ret) return ret;
                // 当前节点就是我们要找的节点
                if(++count == k) return pRoot;
                // 递归右
                ret = KthNode(pRoot->right,k);
                // 返回值不为空，找到了第k大的节点
                if(ret) return ret;
        }
        // 二叉树为空，返回空指针
        return nullptr;
    }    
};
```