//插入排序 O(n^2) 稳定
void insertSort(int A[],int n){
    for(int i = 1;i < n;i++){
        int target = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > get){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = target;
    }
}

//二分插入排序 
void insertSortDichotomy(int A[],int n){
    for(int i = 1;i < n;i++){
        int target = A[i];
        int left = 0;
        int right = i - 1;
        while(left <= right){//二分查找
            int mid = (left + right) / 2;
            if(A[mid] > target){
                right = mid;
            }else{
                left = mid;
            }
        }
        for(int j = i - 1;j >= left;j--){
            A[j + 1] = A[j];
        }
        A[left] = target;
    }
}

//值交换函数
void Swap(int A[],int i,int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

//选择排序 不稳定
void selectSort(int A[],int n){
    for(int i = 0;i < n - 1;i++){
        int min = i;
        for(int j = i + 1;j < n;j++){
            if(A[j] < A[min]){
                min = j;
            }
        }
        if(min != i){
            Swap(A,min,i);
        }
    }
}

//冒泡排序 不稳定
void BubbleSort(int A[],int n){
    for(int j = 0;j < n - 1;j++){
        for(int i = 0;i < n - 1 - j;i++){
            if(A[i] > A[i+1]){
                Swap(A,i,i+1);
            }
        }
    }
}

//改进的冒泡排序，鸡尾酒排序，双端并进
void CocktailSort(int A[],int n){
    int left = 0;
    int right = n - 1;
    while(left < right){
        for(int i = left;i < right;i++){//右端冒最大值
            if(A[i] > A[i + 1]){
                Swap(A, i, i + 1);
            }
        }
        right--;
        for(int i = right;i > left;i--){//左端冒最小值
            if(A[i -1] > A[i]){
                Swap(A,i - 1,i);
            }
        }
        left++;
    }
}

//快速排序的划分函数
int partition(int A[],int left,int right){
    int pivot = A[right];
    int tail = left - 1;
    for(int i = left;i < right;i++){
        if(A[i] <= pivot){
            Swap(A,++tail,i);
        }
    }
    Swap(A,tail + 1,right);
    return tail + 1;
}

//快速排序函数
void quickSort(int A[],int left,int right){
    if(left >= right){//end entrance
        return;
    }
    int pivot_index = partition(A,left,right);
    quickSort(A,left,pivot_index - 1);
    quickSort(A,pivot_index + 1,right);
}

//堆调整函数
void heapify(int A[],int i,int size){
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int max = i;
    if(left < size && A[left] > A[max]){
        max = left;
    }
    if(right < size && A[right] > A[max]){
        max = right;
    }
    if(max != i){
        Swap(A,i,max){
            heapify(A,max,size);
        }
    }
}

//建堆函数
int buildHeap(int A[],int n){
    int heapSize = n;
    for(int i = heapSize / 2 - 1;i >= 0;i--){
        heapify(A,i,heapSize);
    }
    return heapSize;
}

//堆排序函数
void heapSort(int A[],int n){
    int heapSize = buildHeap(A,n);
    int k = 0;
    while(heapSize > 1){
        Swap(A,0,--heapSize);
        heapify(A,0,heapSize);
    }
}

//归并函数
void merge(int A[],int left,int mid,int right){
    int len = right - left + 1;
    int *temp = new int[len];
    int index = 0;
    int i = left;
    int j = mid + 1;
    while(i <= mid && j <= right){
        temp[index++] = A[i]<=A[j]?A[i++]:A[j++];
    }
    while(i <= mid){
        temp[index++] = A[i++];
    }
    while(j <= right){
        temp[index++] = A[j++];
    }
    for(int k = 0;k < len;k++){//restore
        A[left++] = temp[k];
    }
}

//递归的归并算法
void mergeSortRecursion(int A[], int left,int right){
    if(left == right) return;
    int mid = (left + right) / 2;
    mergeSortRecursion(A,left,mid);
    mergeSortRecursion(A,mid + 1,right);
    merge(A,left,mid,right);
}

//非递归的归并算法
mergeSortIteration(int A[],int len){
    int left,mid,right;
    for(int i = 1;i < len;i *= 2 ){
        left = 0;
        while(left + i < len){
            mid = left + i - 1;
            right = mid + i < len ? mid + i : len - 1;
            merge(A,left,mid,right);
            left = right;
        }
    }
}

//希尔排序
void shellSort(int A[],int n){
    int h = 0;
    while(h <= n){
        h = h * 3 + 1;
    }
    int k = 0;
    while(h >= 1){//insert sort alg
        for(int i = h;i < n;i++){
            int j = i - h;
            int target = A[i];
            while(j >= 0 && A[j] > target){
                A[j + h] = A[j];
                j = j - h;
            }
            A[j + h] = target;
        }
        h = (h - 1) / 3;
        k++;
    }
}