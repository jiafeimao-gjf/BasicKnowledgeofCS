
#include <iostream>
using namespace std;
void swap(int A[],int i,int j){
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
int partition(int A[],int left,int right){
	int pivot = A[right];
	
	int tail = left-1;
	for(int i = left;i<right;i++){
		if(A[i] <= pivot){
			swap(A,++tail,i);
		}
	}
	swap(A,tail+1,right);
	return tail+1;
}

void QuickSort(int A[],int left,int right){
	if(left >= right){
		return;
	}
	int pivot_index = partition(A,left,right);
	QuickSort(A,left,pivot_index-1);
	QuickSort(A,pivot_index+1,right);
}
int nums[40000];
int main(){
	int N;
	cin>>N;
	for(int i = 0;i < N;i++){
		//cin>>nums[i];
		nums[i] = i+1;
	}
	QuickSort(nums,0,N-1);
	int x = 1,y = N;
	for(int i = 2;i<=N/2;i++){
		if((N%i==0)){
			int max = i >= N/i?i:N/i;
			int min = N/max; 
			if((max - min) <= (y - x)){
				x = min;
				y = max;	
			}
		}
	}
	
	int cx = x,cy = y;
	int Matrix[200][200];
	if(x==1){
		for(int i = N-1;i >= 0;i--){
			cout<<nums[i]<<endl;
		}
	}else{
		int cnt = N-1;
		//剥洋葱
		int t = x/2;
		for(int i = 0;i <= t;i++){
//			cout<<x<<' '<<y<<endl;
//			cout<<i<<"-->"<<x-1; 
			for(int j = i;j <=x-1;j++){//上一层
				Matrix[i][j] = nums[cnt--];
			}
//			cout<<"-->"<<i+1<<"-->"<<y-1;
			for(int j = i+1;j <= y-1;j++){//右一层
				Matrix[j][x-1] = nums[cnt--];
			}
//			cout<<"-->"<<x-2<<"-->"<<i;
			for(int j = i;j <= x-2;j++){//下一层
				Matrix[y-1][j] = nums[cnt--];
			}
//			cout<<"-->"<<y-2<<"-->"<<i+1<<endl; 
			for(int j = i+1;j <= y-2;j++){//左一层 
				Matrix[j][i] = nums[cnt--];
			}
			x--;
			y--;
		}
		for(int i = 0;i < cy;i++){
			for(int j = 0;j < cx;j++){
				cout<<Matrix[i][j];
				if(j != cx-1){
					cout<<' ';
				}else{
					cout<<endl;
				}
			}
		}
	}

	return 0;
}
