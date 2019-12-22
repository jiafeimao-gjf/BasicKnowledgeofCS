#include <iostream>
#include <ctime> 
#include "sortAlg.cpp" 
using namespace std;

int main(){
	int A[100000];
	srand((unsigned)time(NULL));
	for(int i = 0; i < 100000;i++){//0.1500s
		A[i] = rand()%100000+1;
	}
	//插入排序 
	InsertionSort(A,100000);//10.0s
	//二分插入排序 
//	InsertionSortDichotomy(A,100000);//7.5s
	//选择排序
//	SelectionSort(A,100000);//17.9s
	//冒泡排序
//	BubbleSort(A,100000); //50.0s
	//鸡尾酒排序 
//	CocktailSort(A,100000); //42.3s
	//快速排序
//	QuickSort(A,0,99999); //0.1500s
	//堆排序 
//	HeapSort(A,100000);//0.1750s
	//归并排序,递归式 
//	MergeSortRecursion(A,0,99999); //0.1750s 
	//归并排序,非递归 
//	MergeSortIteration(A,100000);//0.1800s
	//希尔排序
//	ShellSort(A,100000);//0.1800s 
	return 0;
} 
