#include <cstdio>
#include <vector>//动态数组模版 
#include <queue>//双端队列模版 
//完全二叉树，前n-1层是一个满二叉树，左后一层的节点都紧凑排在左边 
//满二叉树 
using namespace std;
vector<int> levelOrder(struct Node* tree);//层序函数声明 
struct Node{ //树的结点结构体声明 ，指针定义法 
	int val;
	struct Node *left,*right;
};
struct Node* leftRotate(struct Node *tree){//左旋函数 
	printf("%d在左旋\n",tree->val); 
	//右助理的左帮手作老板的右助理，老板作右助理的左助手，右助理为新任老板 
	struct Node *temp = tree->right;//抢夺右子树领导权 
	tree->right = temp->left;//右子树改名换姓 
	temp->left = tree;//右子树将父亲归为左子树 
	return temp;//右子树称王 
} 
struct Node* rightRotate(struct Node* tree){//右旋函数
	printf("%d在右旋\n",tree->val);
	struct Node* temp = tree->left;//抢夺左子树领导权 
	tree->left = temp->right;//左子树改名换姓 
	temp->right = tree;//左子树将父亲归为右子树 
	return temp;//左子树称王 
}
int getHeight(struct Node *tree){//递归回溯求tree节点的高度 
	if(tree == NULL) return 0;//tree为空节点，返回高度为0，退出递归 
	int l = getHeight(tree->left);//递归求左子树的高度 
	int r = getHeight(tree->right);//递归求右子树的高度 
	return l > r ? l + 1 : r + 1;//返回较高的那个子树 
}
struct Node* leftRightRotate(struct Node* tree){//先左旋后右旋 
	printf("%d在左右旋\n",tree->val);
	tree->left = leftRotate(tree->left);//将左孩子左旋 
	tree = rightRotate(tree);//将自己右旋 
	return tree;
}
struct Node* rightLeftRotate(struct Node* tree){//先右旋后左旋 
	printf("%d在右左旋\n",tree->val);
	tree->right = rightRotate(tree->right);//将右孩子右旋 
	tree = leftRotate(tree);//将自己左旋 
	return tree;
}
struct Node* insert(struct Node* tree,int val){//递归查找插入算法 
	if(tree == NULL){//空节点开辟空间，赋值并返回 
		tree = new struct Node();
		tree->val = val;
		return tree;
	}
	if(tree->val > val){//应插入左子树 
		tree->left = insert(tree->left,val);
		//获取左右子树的高度 
		int l = getHeight(tree->left);
		int r = getHeight(tree->right);
		//只可能左高右低 
		if(l - r >= 2){ //左子树的深度比右子树大2 
			//插入元素的值小于左子树的值，进行右旋操作 
			if(val < tree->left->val) {
				printf("%d导致了右旋\n",val);
				tree = rightRotate(tree);
			} 
			//否则，需进行先左旋后右旋操作 
			else {
				printf("%d导致了左右旋\n",val);
				tree = leftRightRotate(tree);
			} 
		}
	} else{//应插如右子树 
		tree->right = insert(tree->right,val);
		int l = getHeight(tree->left);
		int r = getHeight(tree->right);
		if(r - l >= 2){
			if(val > tree->right->val) {
				printf("%d导致了左旋\n",val);
				tree = leftRotate(tree);
			}
			else {
				printf("%d导致了右左旋\n",val);
				tree = rightLeftRotate(tree);
			}
		}	
	}
	return tree;
}
int isComplete = 1,after = 0;//after标记第一个左孩子为空的时刻 
//根据层序从上到下，从左至右的特点，用after标记第一个左孩子或者右孩子为空的节点 
vector<int> levelOrder(struct Node* tree){//层序遍历 
	vector<int> v;
	queue<struct Node*> q;
	q.push(tree);
	while(q.size() != 0){//队列不为空 
		//队首元素出队 
		struct Node* temp = q.front();
		q.pop();
		v.push_back(temp->val);
		
		if(temp->left !=  NULL){//左孩子入队 
			if(after) isComplete = 0;
			q.push(temp->left);
		} else{//左孩子为空，则剩下所有节点的左、右孩子都为空，否则当前状态不是完全态 
			after = 1;
		}
		if(temp->right != NULL){//右孩子入队
			if(after) isComplete = 0;
			q.push(temp->right);
		}else{//右子树为空，则剩下所有节点的左、右孩子都为空，否则当前状态不是完全态 
			after = 1;
		}
	}
	return v;
}
int main(){
	int n = 0;
	scanf("%d",&n);
	struct Node* tree = NULL;
	for(int i = 0;i < n;i++){
		int temp;
		scanf("%d",&temp);
		tree = insert(tree,temp);
	}
	vector<int> v = levelOrder(tree);
	for(int i = 0;i < v.size();i++){
		if(i != 0) printf(" ");
		printf("%d",v[i]);
	}
	printf("\n%s",isComplete?"YES":"NO");
	return 0;
}
