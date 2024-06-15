---
title: 旋转数组中最小的数字
categories:
  - 剑指offer
tags:
  - 数组
date: 2019-12-26 23:12:31
---

## 题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

### 解题思路
- 非递减数组的一个旋转，将其旋转回原来的非递减数组，就可以找打最小的元素
- 二分查找
```cpp
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        // 特殊情况
        if(rotateArray.size()==0) return 0;
        // 开始翻转
        int left = 0;
        int right = rotateArray.size()-1;
        int midIndex = 0;// 中间值的索引
        while(rotateArray[left] >= rotateArray[right]){
            if (right - left == 1){ // 纯单增数组，到达最后，数组没有被旋转
                midIndex = right;
                break;
            }
            midIndex = (left + right)/2;
            // 非递减情况，左右值相等，找到了极小值区间
            if (rotateArray[left] == rotateArray[right] && 
                rotateArray[left] == rotateArray[midIndex]){
                int min = rotateArray[left];
                // 遍历求最小值
                for (int i = left;i <= right;++i){
                    if (min > rotateArray[i]){
                        min = rotateArray[i];
                        midIndex = i;
                    }
                }
                break;
            }
            // 二分更新
            if (rotateArray[left] <= rotateArray[midIndex]){
                left = midIndex;
            }else if(rotateArray[right] >= rotateArray[midIndex]){
                right = midIndex;
            }
        }
        return rotateArray[midIndex];
    }
};
```