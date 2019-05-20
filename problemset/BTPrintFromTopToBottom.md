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
        queue<TreeNode*> queue_tree;
        if (root == nullptr) {
            return ans;
        } else {
            queue_tree.push(root);
            while(!queue_tree.empty()){
                TreeNode * node = nullptr;
                node = queue_tree.front();
                queue_tree.pop();
                ans.push_back(node->val);
                if (node->left != nullptr) {
                    queue_tree.push(node->left);
                }
                if (node->right != nullptr) {
                    queue_tree.push(node->right);
                }
            }
            return ans;
        }
    }
};

```