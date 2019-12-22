#include <iostream>

using namespace std;

int graph[100][100];
void dijkstra(int g[][],int src,int dist,int n){
	int w = 65535;
	int allw = 0;
	int v0 = _src;
	int _src = src;
	int S[100] ={0};
	S[_src] = 1;
	for(int i = 0;i < N;i++){
		int min = -1;
		for(int j = 0;j <N;j++){
			if(g[_src][i] != -1){
				if(allw + g[_src][i] < w){
					w = g[_src][i] + allw;
					v0 = i;
				}
			}
		}
		allw += w;
		_src = v0;
		
	}
}
int main(){
	for(int i = 0;i < 100;i++){
		for(int j = i;j < 100;j++){
			graph[i][j] = -1;
			graph[j][i] = -1;
		}
	}
	
	int v1,v2,w;
	int N;
	cin>>N;
	int t = N;
	while(t--){
		cin>>v1>>v2>>w;
		graph[v1][v2] = w;
		graph[v2][v1] = w;
	}
	
	
} 
