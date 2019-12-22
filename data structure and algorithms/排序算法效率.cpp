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
	//²åÈëÅÅÐò 
	InsertionSort(A,100000);//10.0s
	//¶þ·Ö²åÈëÅÅÐò 
//	InsertionSortDichotomy(A,100000);//7.5s
	//Ñ¡ÔñÅÅÐò
//	SelectionSort(A,100000);//17.9s
	//Ã°ÅÝÅÅÐò
//	BubbleSort(A,100000); //50.0s
	//¼¦Î²¾ÆÅÅÐò 
//	CocktailSort(A,100000); //42.3s
	//¿ìËÙÅÅÐò
//	QuickSort(A,0,99999); //0.1500s
	//¶ÑÅÅÐò 
//	HeapSort(A,100000);//0.1750s
	//¹é²¢ÅÅÐò,µÝ¹éÊ½ 
//	MergeSortRecursion(A,0,99999); //0.1750s 
	//¹é²¢ÅÅÐò,·ÇµÝ¹é 
//	MergeSortIteration(A,100000);//0.1800s
	//Ï£¶ûÅÅÐò
//	ShellSort(A,100000);//0.1800s 
	return 0;
} 
