## 题目描述
给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。

```C++
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
        if(count > k || pRoot == null)
            return null;
        TreeNode p = pRoot;
        Stack<TreeNode> LDRStack = new Stack<TreeNode>();
        TreeNode kthNode = null;
        while(p != null || !LDRStack.isEmpty()){
            while(p != null){
                LDRStack.push(p);
                p = p.left;
            }
            TreeNode node = LDRStack.pop();
            System.out.print(node.val+",");
            count++;
            if(count == k){
                kthNode = node;
            }
            p = node.right;
        }
        return kthNode;
    }
}
```