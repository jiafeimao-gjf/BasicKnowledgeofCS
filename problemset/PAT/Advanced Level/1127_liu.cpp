#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> in,post;//中序遍历和后序遍历序列 
vector<int> result[35];//存储每一层的从左至右的序列
int n,tree[35][2],root;
struct node{//记录对应节点的深度 
	int index,depth;
};
void dfs(int &index,int inLeft,int inRight,int postLeft,int postRight){//递归建树 
	if(inLeft > inRight) return;
	index = postRight;//后序的根在右侧 
	int i = inLeft;//为什么从0开始？而不是从inLeft 
	while(in[i] != post[postRight]) i++;
	dfs(tree[index][0],inLeft,i - 1,postLeft,postLeft + (i - inLeft) - 1);//左子树递归 
	dfs(tree[index][1],i + 1,inRight,postLeft + (i - inLeft),postRight - 1);
}
void bfs(){//层序遍历 
	queue<node> q;
	q.push(node{root, 0});
	while(!q.empty()){
		node temp = q.front(); //获得队首元素 
		q.pop();
		result[temp.depth].push_back(post[temp.index]);//按从左至右的顺序存储对应层次的节点 
		if(tree[temp.index][0] != 0)//左子树非空，入队 
			q.push(node{tree[temp.index][0],temp.depth + 1});
		if(tree[temp.index][1] != 0)//右子树非空，入队 
			q.push(node{tree[temp.index][1],temp.depth + 1});
	}
}
int main(){
	cin>>n;
	in.resize(n + 1);post.resize(n + 1);
	for(int i = 1;i <= n; i++) cin >> in[i];
	for(int i = 1;i <= n; i++) cin >> post[i];
	dfs(root,1,n,1,n);
	bfs();
	printf("%d",result[0][0]);//第一层只有一个根节点 
	for(int i = 1;i < 35; i++){
		if(i % 2 == 1){//奇数层从左至右 
			for(int j = 0;j < result[i].size(); j++){
				printf(" %d",result[i][j]);
			}
		}else{//偶数层从右至左 
			for(int j = result[i].size() - 1;j >= 0; j--){
				printf(" %d",result[i][j]);
			}
		}
	}
	return 0;	
}
