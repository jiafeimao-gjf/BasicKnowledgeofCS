#include <iostream>

using namespace std;

int origin[101];
int origin1[101];
int middle[101];

void InsertSort(int A[],int n){
	int isover = false;
	for(int i = 1;i < n;i++){
		for(int j = 0;j < n;j++){
			if(A[j]!=middle[j]){
				break;
			}else if(j == n-1){
				isover = true;
			}
		}
		int get =  A[i];
		int left = 0;
		int right = i - 1;
		//二分查找循环 
		while(left <= right){
			int mid = (left + right)/2;
			if(A[mid] > get) right = mid - 1;
			else left = mid + 1; 
		}
		for(int j = i -1;j >= left;j--){
			A[j+1] = A[j];
		}
		A[left] = get;
		if(isover){
			cout<<"Insertion Sort"<<endl;
			for(int j = 0;j < n;j++){
				cout<<A[j];
				if(j!=n-1) cout<<' ';
			}
			cout<<endl;
			return;
		}
	} 
}

void Merge(int A[],int left,int mid,int right){
	int len = right - left + 1;
	int *temp = new int[len];
	int index = 0;
	int i = left;
	int j = mid + 1;
	while(i <= mid && j <= right){
		temp[index++] = A[i]<A[j]?A[i++]:A[j++];
	} 
	while(i<=mid){
		temp[index++] = A[i++];
	}
	while(j <= right){
		temp[index++] = A[j++];
	}
	for(int k = 0;k < len;k++){
		A[left++] = temp[k];
	}
}

bool MergeSort(int A[],int len){
	int left,mid,right;
	int n = len;
	int isover = false;
	for(int i = 1;i < len;i *= 2){
		for(int j = 0;j < n;j++){
			if(A[j] != middle[j]){
				break;
			}else if(j == n-1){
				isover = true;
			}
		}
		left = 0;
		while(left + i < len){
			mid = left + i - 1;
			right = mid + i < len ?mid + i:len - 1;
			Merge(A,left,mid,right);  
			left = right + 1;
		}
		if(isover){
			cout<<"Merge Sort"<<endl;
			for(int j = 0;j < n;j++){
				cout<<A[j];
				if(j!=n-1) cout<<' ';
			}
			cout<<endl;
			return true;
		}
	}
	return false;
}

int main(){
	int N;
	cin>>N;
	for(int i = 0;i < N;i++){
		cin>>origin[i];
		origin1[i] = origin[i];
	}
	for(int i = 0;i < N;i++){
		cin>>middle[i];
	}
	
	if(!MergeSort(origin,N)){
		InsertSort(origin1,N);	
	}
	
	return 0;
}
