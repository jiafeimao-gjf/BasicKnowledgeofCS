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
	//�������� 
	InsertionSort(A,100000);//10.0s
	//���ֲ������� 
//	InsertionSortDichotomy(A,100000);//7.5s
	//ѡ������
//	SelectionSort(A,100000);//17.9s
	//ð������
//	BubbleSort(A,100000); //50.0s
	//��β������ 
//	CocktailSort(A,100000); //42.3s
	//��������
//	QuickSort(A,0,99999); //0.1500s
	//������ 
//	HeapSort(A,100000);//0.1750s
	//�鲢����,�ݹ�ʽ 
//	MergeSortRecursion(A,0,99999); //0.1750s 
	//�鲢����,�ǵݹ� 
//	MergeSortIteration(A,100000);//0.1800s
	//ϣ������
//	ShellSort(A,100000);//0.1800s 
	return 0;
} 
