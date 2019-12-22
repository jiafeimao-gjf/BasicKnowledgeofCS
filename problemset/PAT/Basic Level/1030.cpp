//1030. ��������(25)

#include <stdio.h>

void Swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int Partition(int A[], int left, int right)  // ���ֺ���
{
    int pivot = A[right];               // ����ÿ�ζ�ѡ�����һ��Ԫ����Ϊ��׼
    int tail = left - 1;                // tailΪС�ڻ�׼�����������һ��Ԫ�ص�����
    for (int i = left; i < right; i++)  // ������׼���������Ԫ��
    {
        if (A[i] <= pivot)              // ��С�ڵ��ڻ�׼��Ԫ�طŵ�ǰһ��������ĩβ
        {
            Swap(A, ++tail, i);
        }
    }
    Swap(A, tail + 1, right);           // ���ѻ�׼�ŵ�ǰһ��������ĺ�ߣ�ʣ�µ���������Ǵ��ڻ�׼��������
                                        // �ò������п��ܰѺ���Ԫ�ص��ȶ��Դ��ң����Կ��������ǲ��ȶ��������㷨
    return tail + 1;                    // ���ػ�׼������
}

void QuickSort(int A[], int left, int right)
{
    if (left >= right)
        return;
    int pivot_index = Partition(A, left, right); // ��׼������
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
