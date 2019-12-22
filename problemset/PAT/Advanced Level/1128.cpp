/*
1128:N Queens Puzzle 
对于每个位置a[i][j]有三个参数一个是所在行，
所在正对角线，所在副对角线，这三个参数唯一确定了一个位置
因此只要记录每个Queen的这三个元素就行了 
*/
#include <iostream>
#include <cstring>
using namespace std;

bool isASolution(int a[],int N){
	bool flag = true;
	int para[3][2*1001];//记录每个Queen的参数 
	memset(para,0,sizeof(para));
	for(int i = 1;i <= N;i++){
		if(para[0][a[i]]||para[1][a[i] + i]||para[2][a[i] - i + N]){//相关参数已经被占据，则该皇后分布无效 
			flag = false;
			break;
		}
		//否则该皇后可以占据这三个参数 
		para[0][a[i]] = 1;//
		para[1][a[i]+i] = 1;
		para[2][a[i] - i + N] = 1;
	}
	return flag;
}

int main(){
	int k = 0,N;
	int a[1001];
	cin>>k;
	while(k--){
		cin>>N;
		for(int i = 1;i <= N; i++){
			cin>>a[i];
		}
		if(isASolution(a,N)){
			cout<<"YES"<<endl; 
		} else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
} 
