#include <cstdio>
#include <map>
using namespace std;
struct Node{
	int val;
	struct Node *left,*right;
	Node(){
		left = right = NULL;
	}
};
map<int,bool> vs;
bool isFound(int a){
	if(vs.find(a) != vs.end()) return true;
	else return false;
}
Node* insert(struct Node* tree,int val){//搜索树插入，标准算法 
	if(tree == NULL){
		tree = new struct Node();
		tree->val = val;
		return tree;
	}
	if(tree->val > val) tree->left =  insert(tree->left,val);
	if(tree->val <= val) tree->right =  insert(tree->right,val);
	return tree;
}
struct Node *lowestCommonAncestor(Node *root,int v,int u){
	if(root == NULL) return NULL;
	if((v >= root->val && u <= root->val) || (v <= root->val && u >= root->val)) 
		return root;
	if(v > root->val && u > root->val) return lowestCommonAncestor(root->right,v,u);
	if(v < root->val && u < root->val) return lowestCommonAncestor(root->left,v,u);
}
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	int val;
	struct Node *tree = NULL;
	for(int i = 0;i < n;i++){
		scanf("%d",&val);
		vs[val] = true;
		tree = insert(tree,val);
	}
	int u,v;
	for(int i = 0;i < m;i++){
		scanf("%d %d",&v,&u);
		if(isFound(v) && isFound(u)){
			struct Node *an = lowestCommonAncestor(tree,v,u);
			if(an->val!=v&&an->val!=u) 
				printf("LCA of %d and %d is %d.\n",v,u,an->val);
			else if(an->val==v)
				printf("%d is an ancestor of %d.\n",v,u);
			else printf("%d is an ancestor of %d.\n",u,v);
		}else{
			if(isFound(v) && !isFound(u)){
				printf("ERROR: %d id not found.\n",u);
			}else if(!isFound(v) && isFound(u)){
				printf("ERROR: %d id not found.\n",v);
			}else{
				printf("ERROR: %d and %d id not found.\n",v,u);
			}
		}
	}
}
