//1008. ����Ԫ��ѭ���������� (20)

//ģ��Ӳ�� 

#include <iostream>

using namespace std;

int main(){
	int t,times,k = 0;
	cin>>t>>times;
	times = times % t;
	int nums[101];
	while(t--){
		cin>>nums[k++]; 
	}
	while(times--){//һ��һ�ε��� 
		int temp = nums[k-1];//������һ������
		for(int j = k-1;j > 0;j--){//Ӧ�Ӻ���ǰ�ƣ���ǰ�����ƻᱻ���� 
			nums[j] = nums[j-1];//����һλ
		}
		nums[0] = temp;//���һ������������һλ 
	}
	
	for(int i = 0;i < k;i++){
		cout<<nums[i];
		if(i != k-1){
			cout<<' ';
		}
	}
	return 0;
}
