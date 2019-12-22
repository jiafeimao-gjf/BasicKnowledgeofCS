//1030. 完美数列(25)

#include <stdio.h>

void Swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int Partition(int A[], int left, int right)  // 划分函数
{
    int pivot = A[right];               // 这里每次都选择最后一个元素作为基准
    int tail = left - 1;                // tail为小于基准的子数组最后一个元素的索引
    for (int i = left; i < right; i++)  // 遍历基准以外的其他元素
    {
        if (A[i] <= pivot)              // 把小于等于基准的元素放到前一个子数组末尾
        {
            Swap(A, ++tail, i);
        }
    }
    Swap(A, tail + 1, right);           // 最后把基准放到前一个子数组的后边，剩下的子数组既是大于基准的子数组
                                        // 该操作很有可能把后面元素的稳定性打乱，所以快速排序是不稳定的排序算法
    return tail + 1;                    // 返回基准的索引
}

void QuickSort(int A[], int left, int right)
{
    if (left >= right)
        return;
    int pivot_index = Partition(A, left, right); // 基准的索引
    QuickSort(A, left, pivot_index - 1);
    QuickSort(A, pivot_index + 1, right);
}

int main(){
	int N,p;
	int nums[100001];
	scanf("%d %d",&N,&p);
	int k = 0;
	while(k<N){
		scanf("%ld",&nums[k++]);
	}
	QuickSort(nums,0,k-1);

	int cnt1 = 0;
	for(int i = 0;i < k-1;i++){
		if(nums[i]*p >= nums[k-1]){
			cnt1 = k - i;
			break;
		}
		if(i==k-2){
			cnt1 = 1;
		}
	}
	int cnt2 = 0;
	for(int i = k-1;i > 0;i--){
		if(nums[0]*p >= nums[i]){
			cnt2 = i + 1;
			break;
		}
		if(i==1){
			cnt2 = 1;
		}
	}
	//printf("%ld %ld\n",cnt1,cnt2);
	printf("%ld\n",cnt1>=cnt2?cnt1:cnt2);
	return 0;
} 
