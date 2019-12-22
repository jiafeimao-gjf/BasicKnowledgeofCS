//Dijkstra

#include <cstdio>
#include <algorithm>

int main(){
	int e[5][5]={
	{100,2,4,1,100},
	{2,100,2,1,5},
	{4,2,100,2,3},
	{1,1,2,100,2},
	{100,5,3,2,100},};
	
	int dis[5]={100,100,100,100,100},pre[5] = {0,1,2,3,4};
	int s = 3;
	dis[s] = 0;
	bool visit[5] = {false};
	for(int i = 0;i < 5;i++){
		int u = -1,minn = 100;
		for(int j = 0;j < 5;j++){//????????????????????§³????????¡À? 
			if(visit[j]==false && dis[j] < minn){
				u = j;
				minn = dis[j];
			}
		}
		if(u == -1) return 0;
		visit[u] = true;//???¦Ë????? 
		for(int v = 0;v < 5; v++){//????dis???? 
			if(visit[v] == false && e[u][v] != 100 && dis[u] + e[u][v] < dis[v]){
				dis[v] = dis[u] + e[u][v];//????s-->v????? 
				pre[v] = u;//????v????????? 
			}
		}
	}
	
	for(int i = 0;i < 5;i++){
		printf("%d-->%d????§³????:%d\n",s,i,dis[i]);
		printf("¡¤????%d",i);
		int p = i;
		while(pre[p] != s){
			printf("<--%d",pre[p]);
			p = pre[p];
		}
		printf("<--%d\n",s);
	}
	return 0;
} 
