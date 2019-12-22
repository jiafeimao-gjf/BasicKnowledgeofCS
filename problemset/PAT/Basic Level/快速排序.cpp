
void swap(int A[],int i,int j){
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

int partition(int A[],int left,int right){
	int pivot = A[right];//���������
	int tail = left-1;//С��������
	for (int i = left;i < right; ++i){//�Ƴ�ǽ��һȦ
		if(A[i] <= pivot)//С����
		{
			swap(A,++tail,i);//����Ҳ
		}
	}
	swap(A,tail+1,right);//�ұ��������������
	
	return tail+1;//�����ҵ�λ��
}

void quicksort(int A[],int left,int right){
	if(left >= right){//С�Ӳ��ұ����� 
		return;
	}
	int pivot_index = partition(A,left,right);//���������ģ�����pivot_index 
	quicksort(A,left,pivot_index -1);//�Ҵ���������� 
	quicksort(A,pivot_index + 1,right);//�Ҵ���������� 
}
