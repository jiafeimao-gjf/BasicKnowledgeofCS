#include <cstdio>
#include <iostream>
//#include <algorithm>
#include <vector>
using namespace std;
vector<int> v[100];//�ڽӱ� 
int book[100],maxdepth = -1;

void dfs(int index,int depth){//����������� 
	if(v[index].size() == 0){//�ýڵ�û�к��ӣ��ݹ��ս����� 
		book[depth]++;// ��depth�����Ҷ��Ŀ��һ 
		maxdepth = max(maxdepth,depth);//���������� 
		return;
	}
	//�ڵ�index�к��ӣ���dfs�亢�� 
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
