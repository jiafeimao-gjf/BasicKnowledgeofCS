#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;
struct node{
	int p,q;
};
bool g[10000][10000];
bool cmp(node a,node b){
	return a.p != b.p ? a.p < b.p : a.q < b.q;
}
int main(){
	int n,m,K;
	scanf("%d",&n,&m);
	vector<int> friends[10000];
	for(int i = 0;i < m;i++){
		string a,b;
		cin>>a>>b;
		if(a.length() == b.length()){
			friends[abs(atoi(a.c_str()))].push_back(abs(atoi(b.c_str())));
			friends[abs(atoi(b.c_str()))].push_back(abs(atoi(a.c_str())));
		}
		g[abs(atoi(a.c_str()))][abs(atoi(b.c_str()))] = g[abs(atoi(b.c_str()))][abs(atoi(a.c_str()))] = true;
	} 
	scanf("%d",&K);
	for(int i = 0;i < K;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		vector<node> res;
		for(int j = 0;j < friends[abs(a)].size();j++){
			for(int k = 0;k < friends[abs(b)].size();k++){
				if(friends[abs(a)][j] == abs(b) || friends[abs(b)][k] == abs(a)){//不能找直接是朋友关系的 
					continue;
				}
				if(g[friends[abs(a)][j]][friends[abs(b)][k]]) {//朋友之间是朋友 
					node f = {friends[abs(a)][j],friends[abs(b)][k]};
					res.push_back(f);
				}
			}
		}
		sort(res.begin(),res.end(),cmp);
		printf("%d\n",res.size());
		for(int j = 0;j < res.size();j++){
			printf("%04d %04d\n",res[i].p,res[i].q);
		} 
	}
	return 0;
}
