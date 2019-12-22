//插入排序，关键是找插入位置 
void InsertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++){ //从第二个元素开始遍历 
    	int get = A[i];		//获取第i个要排序的元素           
        int j = i - 1;		//前j个元素已经排好序                 
        //将当前的元素插入到有序的前j个元素数组中 
        while (j >= 0 && A[j] > get) //从大到小遍历，寻找第一个小于待插元素的位置，边找边移动位置 
        {//找到了当前元素应该所在的位置，A[j] > get，表示当前序列是递增排序的，因为要找到第一个小于
		//排序元素的位置就停止循环，该循环是将所有大于get的元素后移一位 
            A[j + 1] = A[j];
			j--;//比较元素位置前移一位，继续查找
        }
        A[j + 1] = get;//此时 A[j] <= get ,将get插入到 j+1个位置因为j--了，所以用j + 1 
    }
}

//二分插入排序 
void InsertionSortDichotomy(int A[], int n)
{
    for (int i = 1; i < n; i++){
        int get = A[i];                    // 右手抓到一张扑克牌
        int left = 0;                    // 拿在左手上的牌总是排序好的，所以可以用二分法
        int right = i - 1;                // 手牌左右边界进行初始化
        while (left <= right){            // 采用二分法定位新牌的位置
            int mid = (left + right) / 2;//获得有序序列的中间值索引 
            if (A[mid] > get)//中间值较大 
                right = mid - 1;//舍去上半序列 
            else //中间值较小 
                left = mid + 1;//舍去下半序列 
        }
        for (int j = i - 1; j >= left; j--)    // 将欲插入新牌位置右边的牌整体向右移动一个单位
        {
            A[j + 1] = A[j];
        }
        A[left] = get;                    // 将抓到的牌插入手牌
    }
}

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
        int min = i;//记录当前待排序的元素
        for (int j = i + 1; j < n; j++)  // 子循环，完成找到当前未排序序列的最小值  
        {
            if (A[j] < A[min]){
                min = j;
            }
        }
        if (min != i) // 如果当前元素不是最小值，将当前最小值与待排序位置值互换 
        {
            Swap(A, min, i);
        }
    }
}

//冒泡排序 
void BubbleSort(int A[], int n)
{
    for (int j = 0; j < n - 1; j++)         // 每次最大元素就像气泡一样"浮"到数组的最后，使序列变得有序 
    {
        for (int i = 0; i < n - 1 - j; i++) // 依次比较相邻的两个元素,冒出最大的元素， 
        {
            if (A[i] > A[i + 1])            // 如果条件改成A[i] >= A[i + 1],则变为不稳定的排序算法
            {
                Swap(A, i, i + 1);
            }
        }
    }
}

//鸡尾酒排序 
void CocktailSort(int A[], int n)
{
    int left = 0;                            // 初始化边界
    int right = n - 1;
    while (left < right)
    {
        for (int i = left; i < right; i++)   // 前半轮,将最大元素放到后面
        {
            if (A[i] > A[i + 1])
            {
                Swap(A, i, i + 1);
            }
        }
        right--;
        for (int i = right; i > left; i--)   // 后半轮,将最小元素放到前面
        {
            if (A[i - 1] > A[i])
            {
                Swap(A, i - 1, i);
            }
        }
        left++;
    }
}
int Partition(int A[], int left, int right)  // 划分函数
{
    int pivot = A[right];               // 这里每次都选择最后一个元素作为基准
    int tail = left - 1;                // tail为小于基准的子数组最后一个元素的索引
    for (int i = left; i < right; i++)  // 遍历基准以外的其他元素
    {
        if (A[i] <= pivot)              // 该元素小于等于基准
        {
            Swap(A, ++tail, i);			// 该元素放到前一个子数组末尾
        }
    }
    Swap(A, tail + 1, right);           // 最后把基准放到前一个子数组的后边，剩下的子数组就是大于基准的子数组
                                        // 该操作很有可能把后面元素的稳定性打乱，所以快速排序是不稳定的排序算法
    return tail + 1;                    // 返回基准的索引
}

//快速排序 
void QuickSort(int A[], int left, int right)
{
    if (left >= right)//递归遍历条件 
        return;
    int pivot_index = Partition(A, left, right); // 获得基准的索引
    QuickSort(A, left, pivot_index - 1);//递归左半部分 
    QuickSort(A, pivot_index + 1, right);//递归右边部分  
}

//堆排序 
void Heapify(int A[], int i, int size)  // 从A[i]向下进行堆调整，size是待排序的元素个数 
{
    int left_child = 2 * i + 1;         // 左孩子索引
    int right_child = 2 * i + 2;        // 右孩子索引
    int max = i;                        // 选出当前结点与其左右孩子三者之中的最大值
    if (left_child < size && A[left_child] > A[max])//当前结点与左孩子比较 
        max = left_child;
    if (right_child < size && A[right_child] > A[max])//当前结点与右孩子比较 
        max = right_child;
    if (max != i)//最大值不是当前结点 
    {
        Swap(A, i, max);                // 把当前结点和它的最大(直接)子节点进行交换 
        Heapify(A, max, size);          // 递归调用，继续从当前结点向下进行堆调整，求子树的最大值 
    }
}

int BuildHeap(int A[], int n)           // 建堆，时间复杂度O(n)
{
    int heap_size = n;
    for (int i = heap_size / 2 - 1; i >= 0; i--) // 从每一个非叶结点开始向下进行堆调整
    // heap_size / 2 - 1 的意思是  这个数之后就没有左右孩子了，所以从这个结点开始 
        Heapify(A, i, heap_size);
    return heap_size;
}

void HeapSort(int A[], int n)
{
    int heap_size = BuildHeap(A, n);    // 建立一个最大堆
    int k = 0;
    while (heap_size > 1)				// 堆（无序区）元素个数大于1，未完成排序
    {
        // 将堆顶元素与堆的最后一个元素互换，并从堆中去掉最后一个元素
        // 此处交换操作很有可能把后面元素的稳定性打乱，所以堆排序是不稳定的排序算法
        Swap(A, 0, --heap_size);
        Heapify(A, 0, heap_size);     // 从新的堆顶元素开始向下进行堆调整，时间复杂度O(logn)
    }
}

//归并排序 
void Merge(int A[], int left, int mid, int right)// 合并两个已排好序的数组A[left...mid]和A[mid+1...right]
{
    int len = right - left + 1;
    int *temp = new int[len];       // 辅助空间O(n)
    int index = 0;
    int i = left;                   // 前一数组的起始元素
    int j = mid + 1;                // 后一数组的起始元素
    while (i <= mid && j <= right)
    {
        temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];  // 带等号保证归并排序的稳定性
    }
    while (i <= mid)
    {
        temp[index++] = A[i++];
    }
    while (j <= right)
    {
        temp[index++] = A[j++];
    }
    for (int k = 0; k < len; k++)
    {
        A[left++] = temp[k];
    }
}

void MergeSortRecursion(int A[], int left, int right)    // 递归实现的归并排序(自顶向下)
{
    if (left == right)    // 当待排序的序列长度为1时，递归开始回溯，进行merge操作
        return;
    int mid = (left + right) / 2;
    MergeSortRecursion(A, left, mid);
    MergeSortRecursion(A, mid + 1, right);
    Merge(A, left, mid, right);
}

void MergeSortIteration(int A[], int len)    // 非递归(迭代)实现的归并排序(自底向上)
{
    int left, mid, right;// 子数组索引,前一个为A[left...mid]，后一个子数组为A[mid+1...right]
    for (int i = 1; i < len; i *= 2)        // 子数组的大小i初始为1，每轮翻倍
    {
        left = 0;
        while (left + i < len)              // 后一个子数组存在(需要归并)
        {
            mid = left + i - 1;
            right = mid + i < len ? mid + i : len - 1;// 后一个子数组大小可能不够
            Merge(A, left, mid, right);
            left = right + 1;               // 前一个子数组索引向后移动
        }
    
    }
}

//希尔排序 
void ShellSort(int A[], int n)
{
    int h = 0;
    while (h <= n) {// 生成初始增量
        h = 3 * h + 1;
    }
    int k = 0; 
    while (h >= 1){
        for (int i = h; i < n; i++){ //插入排序 
            int j = i - h;
            int get = A[i];
            while (j >= 0 && A[j] > get)
            {
                A[j + h] = A[j];
                j = j - h;
            }
            A[j + h] = get;
        }
        h = (h - 1) / 3;                    // 递减增量
        k++;
    }
}
