//1008. 数组元素循环右移问题 (20)

//模拟硬件 

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
	while(times--){//一次一次的移 
		int temp = nums[k-1];//存放最后一个数字
		for(int j = k-1;j > 0;j--){//应从后往前移，从前往后移会被覆盖 
			nums[j] = nums[j-1];//右移一位
		}
		nums[0] = temp;//最后一个数字移至第一位 
	}
	
	for(int i = 0;i < k;i++){
		cout<<nums[i];
		if(i != k-1){
			cout<<' ';
		}
	}
	return 0;
}
