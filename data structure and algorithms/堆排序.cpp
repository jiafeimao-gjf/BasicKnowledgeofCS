#include <stdio.h>

// ���� -------------- �ڲ��Ƚ�����
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- O(nlogn)
// ����ʱ�临�Ӷ� ---- O(nlogn)
// ƽ��ʱ�临�Ӷ� ---- O(nlogn)
// ���踨���ռ� ------ O(1)
// �ȶ��� ------------ ���ȶ�

// ������
/*
 * ��һ�����ѣ���֤���еĸ��ڵ㶼�������Ӧ�����Һ��� 
 * �ڶ��� ������Ԫ�صĸ�����Ϊ 0���Ӷ�ʹ�������Ϊ�������� 
 *
*/ 
void Swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void Heapify(int A[], int i, int size)  // ��A[i]���½��жѵ�����size�Ǵ������Ԫ�ظ��� 
{
    int left_child = 2 * i + 1;         // ��������
    int right_child = 2 * i + 2;        // �Һ�������
    int max = i;                        // ѡ����ǰ����������Һ�������֮�е����ֵ
    if (left_child < size && A[left_child] > A[max])//��ǰ��������ӱȽ� 
        max = left_child;
    if (right_child < size && A[right_child] > A[max])//��ǰ������Һ��ӱȽ� 
        max = right_child;
    if (max != i)//���ֵ���ǵ�ǰ��� 
    {
        Swap(A, i, max);                // �ѵ�ǰ�����������(ֱ��)�ӽڵ���н��� 
        Heapify(A, max, size);          // �ݹ���ã������ӵ�ǰ������½��жѵ����������������ֵ 
    }
}

int BuildHeap(int A[], int n)           // ���ѣ�ʱ�临�Ӷ�O(n)
{
    int heap_size = n;
    for (int i = heap_size / 2 - 1; i >= 0; i--) // ��ÿһ����Ҷ��㿪ʼ���½��жѵ���
    // heap_size / 2 - 1 ����˼��  �����֮���û�����Һ����ˣ����Դ������㿪ʼ 
        Heapify(A, i, heap_size);
    return heap_size;
}

void HeapSort(int A[], int n)
{
    int heap_size = BuildHeap(A, n);    // ����һ������
    int k = 0;
    while (heap_size > 1)				// �ѣ���������Ԫ�ظ�������1��δ�������
    {
        // ���Ѷ�Ԫ����ѵ����һ��Ԫ�ػ��������Ӷ���ȥ�����һ��Ԫ��
        // �˴������������п��ܰѺ���Ԫ�ص��ȶ��Դ��ң����Զ������ǲ��ȶ��������㷨
        Swap(A, 0, --heap_size);
        Heapify(A, 0, heap_size);     // ���µĶѶ�Ԫ�ؿ�ʼ���½��жѵ�����ʱ�临�Ӷ�O(logn)
    }
}

int main()
{
    int A[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8,12,11,10 };// ��С���������
    int n = sizeof(A) / sizeof(int);
    HeapSort(A, n);
    printf("����������");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
