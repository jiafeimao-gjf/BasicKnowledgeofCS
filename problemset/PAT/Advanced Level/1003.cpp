#include <cstdio>
#define INF 100000000
int main(){
	int n,m,c1,c2;
	scanf("%d %d %d %d",&n,&m,&c1,&c2);
	int e[501][501];//�ڽӾ��� 
	int dis[501];//��ʼ�㵽������Ĵ��� 
	int weight[501];//������ĵ�Ȩֵ 
	int num[501];//��¼��ʼ�㵽����������·������ 
	int w[501];//��ʼ�㵽·���ϵĸ���ĵ�Ȩֵ֮�� 
	bool visit[501] = {false};//���ʿ������� 
	for(int i = 0;i < 501;i++){
		dis[i] = INF;
		for(int j = 0;j < 501;j++){
			e[i][j] = INF;
		}
	}
	for(int i = 0;i < n;i++){
		scanf("%d",&weight[i]);
	}
	for(int i = 0;i < m;i++){
		int a,b,val;
		scanf("%d %d %d",&a,&b,&val);
		e[a][b] = e[b][a] = val;
	}
	dis[c1] = 0;
	w[c1] = weight[c1];
	num[c1] = 1;
	//dijkstra�㷨 
	for(int i = 0;i < n;i++){ 
		int u = -1,minn = INF;
		for(int j = 0;j < n;j++){
		//��δ���ʹ���dis����ĸ�Ԫ������·����Сֵ 
			if(visit[j] == false && dis[j] < minn){// 
				u = j;
				minn = dis[j];//������Сֵ 
			}
		}
		if(u == -1) break;//û����Сֵ����������� 
		visit[u] = true;
		for(int v = 0;v < n;v++){
			if(visit[v] == false && e[u][v] != INF){
				if(dis[u] + e[u][v] < dis[v]){
					dis[v] = dis[u] + e[u][v];
					//�������·������
					num[v] = num[u];
					//�������ټ��ľ�Ԯ�Ӹ��� 
					w[v] = w[u] + weight[v]; 
				}else if(dis[u] + e[u][v] == dis[v]){
					//�������·������ 
					num[v] = num[v] + num[u];
					//�������ټ��ľ�Ԯ�Ӹ��� 
					if(w[u] + weight[v] > w[v]){//�����ٻ����ľ�Ԯ�� 
						w[v] = w[u] + weight[v];
					}
				}
			}
		}
	}
	printf("%d %d",num[c2],w[c2]); 
	return 0;
} 
