/*
1128:N Queens Puzzle 
����ÿ��λ��a[i][j]����������һ���������У�
�������Խ��ߣ����ڸ��Խ��ߣ�����������Ψһȷ����һ��λ��
���ֻҪ��¼ÿ��Queen��������Ԫ�ؾ����� 
*/
#include <iostream>
#include <cstring>
using namespace std;

bool isASolution(int a[],int N){
	bool flag = true;
	int para[3][2*1001];//��¼ÿ��Queen�Ĳ��� 
	memset(para,0,sizeof(para));
	for(int i = 1;i <= N;i++){
		if(para[0][a[i]]||para[1][a[i] + i]||para[2][a[i] - i + N]){//��ز����Ѿ���ռ�ݣ���ûʺ�ֲ���Ч 
			flag = false;
			break;
		}
		//����ûʺ����ռ������������ 
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
