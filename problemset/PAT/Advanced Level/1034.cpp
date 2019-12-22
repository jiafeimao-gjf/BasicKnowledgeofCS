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
		//����������ɣ������ǽ����㷨
		bool isvc = true;
		for(int i = 0;i < e.size();i++){//����ÿ���� 
			for(int j = 0;j < vset.size();j++){//���Ƿ����ٺ���һ���� 
				if(vset[j] == e[i].v || vset[j] == e[i].u){//�ҵ��ˣ��˳��ò�ѭ�� 
					break;
				}
				if(j == vset.size() - 1){//�����û�ҵ� 
					isvc = false;//����vc 
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
