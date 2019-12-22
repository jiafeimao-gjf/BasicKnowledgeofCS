#include <iostream>

using namespace std;
void Swap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
} 
void AdjustDown(int A[],int k,int len){
	A[0] = A[k];
	for(int i = 2*k; i <= len; i *= 2){
		if(i < len && A[i] < A[i+1]){
			i++;
		}
		if(A[0] >= A[i]) {
			break;
		}else{
			A[k] = A[i];
			k = i;
		}
	}
	A[k] = A[0];
}

void BuildMaxHeap(int A[],int len){
	for(int i = len/2;i > 0;i--){
		AdjustDown(A,i,len);
	}
}
void HeapSort(int A[],int len){
	BuildMaxHeap(A,len);
	for(int i = len;i > 1;i--){
		Swap(A[i],A[1]);
		AdjustDown(A,1,i-1);
	} 
}
int main(){
	int A[] = {2,4,6,7,1,9,8,5,3};
	HeapSort(A,9);
	for(int i = 1;i < 9;i++){
		cout<<A[1]<<" ";
	}
	return 0;
} 
