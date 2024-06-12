---
title: 算法总结
categories:
  - 算法
tags:
  - 算法总结
date: 2024-06-12 15:22:28
---

[toc]

算法，是需要不断温故算法细节的，这样才能成为精通算法！！！

# 1、排序算法
## 1.1 快速排序

关键词：二分递归、分治

### 算法描述

一句话说明：二分，随机或者按照规则选取一个值，按照值进行二分，将原数组分成一堆大数和一堆小数。递归执行二分。直至完成排序。

描述：
- quickSort参数输入：数组A，排序区间左右下标left、right
  - 数组A区间不合法，即：`left >= right`，退出
  - 获取一个划分下标pIndex，具体实现：
    - 取right的值`p = A[right]`，用于二分
    - 初始化较小部分的最后一个下标 `tail = left - 1`
    - 遍历数组 `for i in left -> right`
      - 所有小于等于p的值（解释：由于大于p的值会被tail索引，所以，swap函数是将较小（`< p`）的值和较大（`> p`）的值进行交换）
        - `tail++`
        - 交换到左侧 `swap(A, tail, i)`
    - 将p值交换到叫较小部分和较大部分的中间 `swap(A, tail + 1, right)`
    - `pIndex = tail + 1`
  - 递归左半部分排序 `quickSort(A, left, pIndex - 1)`
  - 递归左半部分排序 `quickSort(A, pIndex + 1, right)`

### 算法实现
```cpp
int partition(int A[], int left, int right)  // 划分函数
{
    int pivot = A[right];               // 这里每次都选择最后一个元素作为基准
    int tail = left - 1;                // tail为小于基准的子数组最后一个元素的索引
    for (int i = left; i < right; i++)  // 遍历基准以外的其他元素
    {
        if (A[i] <= pivot)  // 该元素小于等于基准
        {
            swap(A, ++tail, i); // 该元素放到前一个子数组末尾
        }
    }
    swap(A, tail + 1, right); // 最后把基准放到前一个子数组的后边，剩下的子数组就是大于基准的子数组
    // 该操作很有可能把后面元素的稳定性打乱，所以快速排序是不稳定的排序算法
    return tail + 1;     // 返回基准的索引
}

//快速排序 
void quickSort(int A[], int left, int right)
{
    if (left >= right)//递归遍历条件 
        return;
    int pivot_index = partition(A, left, right); // 获得基准的索引
    quickSort(A, left, pivot_index - 1);//递归左半部分 
    quickSort(A, pivot_index + 1, right);//递归右边部分  
}
```

## 1.2 堆排序

关键词：完全二叉树数组化、大顶堆、小顶堆

### 算法描述

一句话描述：用数组来构建一个完全二叉树，二叉树的每个根节点满足：左子树 < 根，右子树 < 根。

**描述：**
- `heapSort` 输入：数组A、数组长度n
  - 构建大顶堆，返回对的大小 `heapSize`
    - `heapSize = n` 初始化
    - 按照二叉树遍历: `for i in heapSize/2 - 1 -> 0` （解释: 完全二叉树中，下标`heapSize/2 - 1`的根节点没有左右孩子，因为：n层的完全二叉树，节点数量为 $2^n - 1$，其叶子节点的数量为 $ 2^{n - 1}$，其差值为$2^{n - 1} - 1$，即 `heapSize/2 - 1`）
      - 堆调整 `heapify(A, i, heapSize)` 调整出最大值或者最小值
        - 取左孩子索引 `leftIndex = 2 * i + 1`
        - 取右孩子索引 `rightIndex = 2 * i + 2`
        - 初始化一个最大值索引 `max_index = i`
        - 获取最大值 `if A[leftIndex] > A[max]`
          - 更新max为leftIndex
        - 获取最大值 `if A[rigthIndex] > A[max]`
          - 更新max为rigthIndex
        - `if max != i` 无法保证左右子树的大小关系
        - 交换max和i的值 `swap(A, i, max)` 保证i处的值最大
        - 递归处理 max 的子树的最大值 `heapify(A, max, size)`
  - 遍历 `while heapSize > 1`
    - heapSize--
    - 交换元素 `swap(A, 0, heapSize)`
    - 使用新的heapSize 调整堆，`heapify(A, 0, heapSize)`
      
## 算法实现
- c++
```cpp
//堆排序 
void heapify(int A[], int i, int size)  // 从A[i]向下进行堆调整，size是待排序的元素个数 
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
        swap(A, i, max);                // 把当前结点和它的最大(直接)子节点进行交换 
        heapify(A, max, size);          // 递归调用，继续从当前结点向下进行堆调整，求子树的最大值 
    }
}

int buildHeap(int A[], int n)           // 建堆，时间复杂度O(n)
{
    int heap_size = n;
    for (int i = heap_size / 2 - 1; i >= 0; i--) // 从每一个非叶结点开始向下进行堆调整
    // heap_size / 2 - 1 的意思是  这个数之后就没有左右孩子了，所以从这个结点开始 
        heapify(A, i, heap_size);
    return heap_size;
}

void heapSort(int A[], int n)
{
    int heap_size = buildHeap(A, n);    // 建立一个最大堆
    while (heap_size > 1)				// 堆（无序区）元素个数大于1，未完成排序
    {
        // 将堆顶元素与堆的最后一个元素互换，并从堆中去掉最后一个元素
        // 此处交换操作很有可能把后面元素的稳定性打乱，所以堆排序是不稳定的排序算法
        swap(A, 0, --heap_size);
        heapify(A, 0, heap_size);     // 从新的堆顶元素开始向下进行堆调整，时间复杂度O(logn)
    }
}

```

## 1.3 归并排序

一句话描述：排序小组节点集合，两两归并相邻集合、完成排序。递归思想+归并思想。

### 算法描述

**递归版本描述：**
- 输入A数组，左右区间 left right
  - 非法case `left == right, return`
  - 取中间mid
    - 递归调用归并左边区域 输入A数组，左右区间 left mid
    - 递归调用归并右边区域 输入A数组，左右区间 mid + 1 right
  - 左右区间合并函数 输入`A,left,mid,right`
    - 计算总长度 len
    - 构造临时存储空间 `temp = int[len]` 用于存储合并后的数据
    - 初始化index = 0
    - 初始化 i从左边区间的第一个位置开始 `i = left`
    - 初始化 j 从右边区间的第一个位置开始 `j = mid+1`
    - 循环 i < 左区间最值, j < 右区间最值
      - 按照从小到大的顺序，将左右区间的数字填入 `temp[index]` 然后 `index++`
    - 如果左边区间没有遍历完，继续循环遍历
      - 复制填入到 `temp[index]` 然后 `index++`
    - 如果右边区间没有遍历完，继续循环遍历
      -  复制填入到 `temp[index]` 然后 `index++`
    - 数据还原，将temp的数据还原到A的存储空间中


### 算法代码
```cpp
//归并排序 
void merge(int A[], int left, int mid, int right)// 合并两个已排好序的数组A[left...mid]和A[mid+1...right]
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
    for (int k = 0; k < len; k++) // 将排好序的数组重新复制给原数组
    {
        A[left++] = temp[k];
    }
}

/**
 * 递归实现的归并排序(自顶向下)
 */
void mergeSortRecursion(int A[], int left, int right)   
{
    if (left == right)    // 当待排序的序列长度为1时，递归开始回溯，进行merge操作
        return;
    int mid = (left + right) / 2;
    mergeSortRecursion(A, left, mid);
    mergeSortRecursion(A, mid + 1, right);
    merge(A, left, mid, right);
}


/**
 * 非递归(迭代)实现的归并排序(自底向上)
 */
void mergeSortIteration(int A[], int len)   
{
    int left, mid, right;                   // 子数组索引,前一个为A[left...mid]，后一个子数组为A[mid+1...right]
    for (int i = 1; i < len; i *= 2)        // 子数组的大小i初始为1，每轮翻倍，实现二分
    {
        left = 0;
        while (left + i < len)              // 后一个子数组存在(需要归并) 可以被二分
        {
            mid = left + i - 1;             // 更新mid
            right = mid + i < len ? mid + i : len - 1;// 更新right
            merge(A, left, mid, right); // 合并区间 [left,mid] 和 [mid+1, right]
            left = right + 1;               // 更新 left, 渐进式排序
        }
    
    }
}

```


## 1.4 希尔排序

一句话说明：利用插入排序来排序间隔点，缩小间隔，完成排序！
数量大时，可以用二分插入排序

### 算法描述

**描述：**
- 输入数组A, 数组长度n
  - 初始化 h = 0
  - 循环 `h <= n`
    - 按照系数，递增h
  - 循环 `h >= 1`
    - for i in h,n
      - j 初始化为 i 的后h个元素
      - 临时变量 `get = A[i]`
      - 循环对于每个大于get的A[j]
        - 覆盖掉i处的值 `A[j + h] = A[j];`
        - 更新 `j = j - h`
      - 还原 `A[j + h] = get`
    - 更新h，按照系数递减
### 算法代码

```cpp
//希尔排序 
void mhellSort(int A[], int n)
{
    int h = 0;
    while (h <= n) {                    // 生成初始增量
        h = 3 * h + 1;
    }

    while (h >= 1){
        for (int i = h; i < n; i++){    //插入排序 
            int j = i - h;              // j 初始化为 i 的后h个元素
            int get = A[i];
            while (j >= 0 && A[j] > get)
            {
                A[j + h] = A[j];
                j = j - h;
            }
            A[j + h] = get;
        }
        h = (h - 1) / 3;                // 递减增量
    }
}

```

## 二分查找

二分查找算法是很常用的 $O(logn)$ 算法，其有多种变形方式，来解决不同情形的二分查找问题。

### 算法描述
- 输入：排序数组a，目标值 target
- 初始化左右指针
- 循环 `lefe <= right`
  - 获得mid 值, 取平均值
  - target大于`a[mid]`
    - left 更新为 mid + 1
  - target小于`a[mid]`
    - right 更新为 mid - 1
  - target 等于 `a[mid]`
    - 返回 mid 下标

- 最后没找到，但是我们可以确定第一个大于target的元素


### 算法代码
```java
public int binarySearch(int[] a, int target) {
  int left = 0;
  int right = a.length - 1;

  while (left <= right) {
    int mid = left + (left - right) / 2;
    if (a[mid] < target) {
      left = mid + 1;
    } else if (a[mid] > target) {
      right = mid - 1;
    } else {
      return mid;
    }
  }
  return left;
}
```

## 树
### 递归遍历 
#### 算法描述


#### 算法代码
### 基于栈的深度优先遍历
#### 算法描述


#### 算法代码
### 基于队列的层序遍历
#### 算法描述


#### 算法代码
## 动态规划
### 算法描述


### 算法代码
## 并查集
### 算法描述


### 算法代码
## 树状数组
### 算法描述


### 算法代码
## 图
### 邻接矩阵
#### 算法描述


#### 算法代码
### 邻接表
#### 算法描述


### 算法代码
### 深度优先搜索算法
#### 算法描述


#### 算法代码
### 广度优先搜索算法
#### 算法描述


#### 算法代码
### 拓扑排序算法
#### 算法描述

#### 算法代码