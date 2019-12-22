#include <cstdio>
#include <iostream>
//#include <algorithm>
#include <vector>
using namespace std;
vector<int> v[100];//邻接表 
int book[100],maxdepth = -1;

void dfs(int index,int depth){//深度优先搜所 
	if(v[index].size() == 0){//该节点没有孩子，递归终结条件 
		book[depth]++;// 第depth层的子叶数目加一 
		maxdepth = max(maxdepth,depth);//跟新最大深度 
		return;
	}
	//节点index有孩子，则dfs其孩子 
	for(int i = 0;i < v[index].size();i++){
		dfs(v[index][i],depth + 1);
	}
}
int main(){
	int n,m,k,node,c;
	scanf("%d %d",&n,&m);
	for(int i = 0;i < m;i++){
		scanf("%d %d",&node,&k);
		for(int j = 0;j < k;j++){
			scanf("%d",&c);
			v[node].push_back(c);
		}
	}
	dfs(1,0);
	printf("%d",book[0]);
	for(int i = 1;i <= maxdepth;i++){
		printf(" %d",book[i]);
	}
	return 0;
} 
