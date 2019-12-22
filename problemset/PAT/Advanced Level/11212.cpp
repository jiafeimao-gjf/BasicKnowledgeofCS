#include <iostream>
using namespace std;
int uset[10001];
int degree[10001];
int find(int i){
	int x = i;
	while(uset[x] != x){
		x = uset[x];
	}
	return x;
}

int main(){
	for(int i = 0;i < 10001;i++){
		uset[i] = i;
		degree[i] = 0;
	}
	int N,a,b;
	cin>>N;
	for(int i = 0;i < N - 1;i++){
		cin>>a>>b;
		int x = find(a);
		int y = find(b);
		if(x!=y){
			uset[x] = y;
		}
		degree[a]++;
		degree[b]++;
	}
	int cnt = 0;
	for(int i = 1;i <= N;i++){
		if(uset[i] == i){
			cnt++;
		}
//		cout<<"degree["<<i<<"]="<<degree[i]<<endl;
	}
	if(cnt == 1){
		for(int i = 1;i <= N;i++){
			if(degree[i] > 1){
				for(int j = 1;j <= N;j++){
					uset[j] = i; 
				}
				break;
			}
		}
		for(int i = 1;i <= N;i++){
			if(uset[i] != i && degree[i] == 1){
				cout<<i<<endl;
			}
		}
	}else{
		cout<<"Error: "<<cnt<<" components"<<endl;
	}
	return 0;
}
