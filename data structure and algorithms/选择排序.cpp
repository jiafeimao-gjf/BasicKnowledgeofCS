#include <stdio.h>

// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- O(n^2)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定

void Swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

//选择排序也是一个渐进排序过程，逐个调出最小值（最大值），直至没有未完成 序列为空 
void SelectionSort(int A[], int n)
{
	//排序主循环 
    for (int i = 0; i < n - 1; i++)//最后一个值肯定是最大值，不需要再选择  
    {
    	//记录当前待排序的元素 
        int min = i;
        // 子循环，完成找到当前未排序序列的最小值 
        for (int j = i + 1; j < n; j++)     
        {
            if (A[j] < A[min])    
            {
                min = j;
            }
        }
        // 如果当前元素不是最小值，将当前最小值与待排序位置值互换 
        if (min != i) 
        {
            Swap(A, min, i);
        }
    }
}

int main()
{
    int A[] = { 8, 5, 2, 6, 9, 3, 1, 4, 0, 7 }; // 从小到大选择排序
    int n = sizeof(A) / sizeof(int);
    SelectionSort(A, n);
    printf("选择排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
