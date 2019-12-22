#include <cstdio>
#define INF 100000000
int main(){
	int n,m,c1,c2;
	scanf("%d %d %d %d",&n,&m,&c1,&c2);
	int e[501][501];//邻接矩阵 
	int dis[501];//起始点到各个点的代价 
	int weight[501];//各个点的点权值 
	int num[501];//记录起始点到各个点的最短路径个数 
	int w[501];//起始点到路径上的各点的点权值之和 
	bool visit[501] = {false};//访问控制数组 
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
	//dijkstra算法 
	for(int i = 0;i < n;i++){ 
		int u = -1,minn = INF;
		for(int j = 0;j < n;j++){
		//在未访问过的dis数组的个元素中找路径最小值 
			if(visit[j] == false && dis[j] < minn){// 
				u = j;
				minn = dis[j];//更新最小值 
			}
		}
		if(u == -1) break;//没有最小值，即程序出错 
		visit[u] = true;
		for(int v = 0;v < n;v++){
			if(visit[v] == false && e[u][v] != INF){
				if(dis[u] + e[u][v] < dis[v]){
					dis[v] = dis[u] + e[u][v];
					//更新最短路径个数
					num[v] = num[u];
					//更新能召集的救援队个数 
					w[v] = w[u] + weight[v]; 
				}else if(dis[u] + e[u][v] == dis[v]){
					//更新最短路径个数 
					num[v] = num[v] + num[u];
					//更新能召集的救援队个数 
					if(w[u] + weight[v] > w[v]){//力求召唤最多的救援队 
						w[v] = w[u] + weight[v];
					}
				}
			}
		}
	}
	printf("%d %d",num[c2],w[c2]); 
	return 0;
} 
