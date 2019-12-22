#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct Edge{
	int v,u;
};
vector<Edge> e; 
vector<int> vset;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int v,u;
	for(int i = 0;i < m;i++){
		scanf("%d %d",&v,&u);
		e.push_back(Edge{v,u});
	} 
	int k;
	while(k--){
		scanf("%d",&v);
		vset.clear(); 
		for(int j = 0;j < v;j++){
			scanf("%d",&u);
			vset.push_back(u);
		}
		//数据输入完成，下面是解题算法
		bool isvc = true;
		for(int i = 0;i < e.size();i++){//遍历每条边 
			for(int j = 0;j < vset.size();j++){//找是否至少含有一个点 
				if(vset[j] == e[i].v || vset[j] == e[i].u){//找到了，退出该层循环 
					break;
				}
				if(j == vset.size() - 1){//到最后都没找到 
					isvc = false;//不是vc 
				}
			}
			if(!isvc) {
				printf("No\n");
				break;
			}
		}
		if(isvc) printf("Yes\n");
	}
	return 0;
}
