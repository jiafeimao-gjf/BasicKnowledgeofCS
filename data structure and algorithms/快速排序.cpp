#include <stdio.h>

// ���� ------------ �ڲ��Ƚ�����
// ���ݽṹ --------- ����
// ���ʱ�临�Ӷ� ---- ÿ��ѡȡ�Ļ�׼������󣨻���С����Ԫ�أ�����ÿ��ֻ���ֳ���һ����������Ҫ����n-1�λ��ֲ��ܽ����ݹ飬ʱ�临�Ӷ�ΪO(n^2)
// ����ʱ�临�Ӷ� ---- ÿ��ѡȡ�Ļ�׼������λ��������ÿ�ζ����ȵĻ��ֳ�����������ֻ��Ҫlogn�λ��־��ܽ����ݹ飬ʱ�临�Ӷ�ΪO(nlogn)
// ƽ��ʱ�临�Ӷ� ---- O(nlogn)
// ���踨���ռ� ------ ��Ҫ�ǵݹ���ɵ�ջ�ռ��ʹ��(��������left��right�Ⱦֲ�����)��ȡ���ڵݹ�������ȣ�һ��ΪO(logn)�����ΪO(n)       
// �ȶ��� ---------- ���ȶ�

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
        if (A[i] <= pivot)              // ��Ԫ��С�ڵ��ڻ�׼
        {
            Swap(A, ++tail, i);			// ��Ԫ�طŵ�ǰһ��������ĩβ
        }
    }
    Swap(A, tail + 1, right);           // ���ѻ�׼�ŵ�ǰһ��������ĺ�ߣ�ʣ�µ���������Ǵ��ڻ�׼��������
                                        // �ò������п��ܰѺ���Ԫ�ص��ȶ��Դ��ң����Կ��������ǲ��ȶ��������㷨
    return tail + 1;                    // ���ػ�׼������
}

void QuickSort(int A[], int left, int right)
{
    if (left >= right)//�ݹ�������� 
        return;
    int pivot_index = Partition(A, left, right); // ��û�׼������
    QuickSort(A, left, pivot_index - 1);//�ݹ���벿�� 
    QuickSort(A, pivot_index + 1, right);//�ݹ��ұ߲��� 
    
	printf("�ݹ��㷨��");
	for(int i = 0;i < 20;i++){
		printf("%d ",A[i]);
	} 
	printf("\n"); 
}

int main()
{
    int A[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8,20,19,10,18,11,17,12,16,13,15,14}; // ��С�����������
    int n = sizeof(A) / sizeof(int);
    QuickSort(A, 0, n - 1);
    printf("������������");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
