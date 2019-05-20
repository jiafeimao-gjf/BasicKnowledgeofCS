```c++
/*
二叉树结构
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
    /**
    * 输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
    * 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
    * (注意: 在返回值的list中，数组长度大的数组靠前)
    * 深度优先搜索，保存路径（有多少个叶子就有多少哥路径），前序遍历即可
    * 疑问：没有保证最长路径靠前呀？？？？
    */
    vector<vector<int>> ans;
    vector<int> target;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if (root == nullptr) { // 空节点，不可能有路径，直接返回
            return ans;
        }
        target.push_back(root->val);
        // 判断是否找到目标值，是的话，路径加入到目标数组中
        if ((root->val == expectNumber) && root->left == nullptr && root->right == nullptr){
            ans.push_back(target);
        } 
        FindPath(root->left,expectNumber-root->val);
        FindPath(root->right,expectNumber-root->val);
        if (!target.empty()) {//后退一格
            target.pop_back();
        }
        return ans;
    }
};
```