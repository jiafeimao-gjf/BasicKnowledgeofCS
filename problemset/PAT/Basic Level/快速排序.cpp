
void swap(int A[],int i,int j){
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

int partition(int A[],int left,int right){
	int pivot = A[right];//你就是中心
	int tail = left-1;//小子来护驾
	for (int i = left;i < right; ++i){//绕城墙走一圈
		if(A[i] <= pivot)//小我者
		{
			swap(A,++tail,i);//分离也
		}
	}
	swap(A,tail+1,right);//我变成了真正的中心
	
	return tail+1;//这是我的位置
}

void quicksort(int A[],int left,int right){
	if(left >= right){//小子不敢比您大 
		return;
	}
	int pivot_index = partition(A,left,right);//大王您在哪？您在pivot_index 
	quicksort(A,left,pivot_index -1);//找大王的左诸侯 
	quicksort(A,pivot_index + 1,right);//找大王的右诸侯 
}
