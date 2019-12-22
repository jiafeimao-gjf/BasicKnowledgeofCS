//1122
#include <iostream>
#include <string>
using namespace std;
/**
6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
6
7 5 1 4 3 6 2 5
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 3 4 5 2 6
7 6 1 2 5 4 3 1
*/
int graph[201][201];
string *res;

bool isrepeat(int a[],int n){
	int *b = new int[n-1];
	for(int i = 0;i < n-1;i++){
		b[i] = 0;
	}
	for(int i = 0;i < n;i++){
		b[a[i]-1]++;
	}
	if(b[a[0]-1]!=2){
		delete [] b;
		return true;
	}
	b[a[0]-1]--;//a[0]这个值一定出现两次
	for(int i = 0;i < n-1;i++){
		if(b[i] != 1){
			delete [] b;
			return true;
		}
	}
	delete [] b;
	return false;
}
int main(){
	int N,M,K;
	int x,y;
	for(int i = 0;i <= 200;i++){
		for(int j = i;j <= 200;j++){
			graph[i][j] = -1;
			graph[j][i] = -1;
		}
	}
	cin>>N>>M;
	for(int i = 0;i < M;i++){
		cin>>x>>y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	cin>>K;
	res = new string[K];
	for(int i = 0;i < K;i++){
		int nums;
		cin>>nums;
		int *number = new int [nums];
		int j = 0;
		while(nums--){
			cin>>number[j++];
		}
		if(j != N + 1){
			res[i] = "NO";
		}else{
			if(number[0] != number[j-1] || isrepeat(number,j)){
				res[i] = "NO";
			}else{
				for(int k = 0;k < j - 1;k++){// 0 - j-2==》1-j-1
					if(graph[number[k]][number[k+1]] == -1){//这两个点之间不存在边
						res[i] = "NO";
						break;
					}else if(k == j - 2){
						res[i] = "YES";
						break;
					}
				}
			}
		}
		delete [] number;
	}
	for(int i = 0;i < K;i++){
		cout<<res[i]<<endl;
	}
	delete [] res;
	return 0;
}
