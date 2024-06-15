---
title: 和为S的连续正数序列
categories:
  - 剑指offer
tags:
  - 数组
  - 双指针
date: 2019-12-26 23:12:31
---

## 题目描述
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
输出描述:
> 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

### 思路1
- 双指针，由于数组是有序连续正整数，从小的值开始，
- 逐渐增大rigth，求和
- 然后增大left，求和
- 直到left 超过了中间值的一般

### 思路2
- 一次性求和，判断
- 值小了right增加
- 值大了left增加
- 类利用了二分查找实现

```cpp
class Solution {
public:
    
    vector<int> oneAnswer(int left,int right) {
        vector<int> ans;
        for (int i = left;i <= right;++i) {
            ans.push_back(i);
        }
        return ans;
    }
    /*
        两指针，一个指向1，一个指向2，依次叠加.
    */
    
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        if (sum < 3) {
            return res;
        }
        
        int left = 1;
        int right = 2;
        int middle = (1 + sum)/2;
        int curSum = left + right;
        
        // 下面的算法在求和的同时，完成了排序
        while (left < middle) {// 左端点的值小于目标值的一半
            if (curSum == sum){
                res.push_back(oneAnswer(left,right));
            }
            
            // 当前的值大于目标值 且 最小值小于目标值的一半，
            // 意味着接下来求和序列的长度将会变短
            while (curSum > sum && left < middle) {
                curSum -= left;
                left++;// 左端点增加
                
                if (curSum == sum){
                    res.push_back(oneAnswer(left,right));
                }
            }
            
            right++;// 右端点增加
            curSum += right;// 更新当前的和
        }
        return res;
    }
    
    /*
        1 等差数列求和公式
        2 双指针思路
    */
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        if (sum < 3) {
            return res;
        }
        
        int left = 1;
        int right = 2;
        while (right > left) {
            int curSum = (left+right)*(right-left+1)/2;// 快速求和
            if (curSum == sum) {
                res.push_back(oneAnswer(left,right));
                left++;
            } else if (curSum < sum) {
                right++;
            } else {
                left++;
            }
        }
        return res;
    }
    
};
```

- java实现
```java
class Solution {
    private int[] oneAnswer(int left,int right) {
        int[] ans = new int[right - left + 1];
        for (int i = 0;left <= right;i++,left++) {
            ans[i] = left;
        }
        return ans;
    }
    /*
        方法1：两指针，一个指向1，一个指向2，依次叠加.
    */
    public int[][] findContinuousSequence(int sum) {
        List<int[]> res = new ArrayList<>();
        if (sum < 3) {
            return res.toArray(new int[0][]);
        }
        
        int left = 1;
        int right = 2;
        int middle = (1 + sum)/2;
        int curSum = left + right;
        
        // 下面的算法在求和的同时，完成了排序
        while (left < middle) {// 左端点的值小于目标值的一半
            if (curSum == sum){
                res.add(oneAnswer(left,right));
            }
            
            // 当前的值大于目标值 且 最小值小于目标值的一半，
            // 意味着接下来求和序列的长度将会变短
            while (curSum > sum && left < middle) {
                curSum -= left;
                left++;// 左端点增加
                
                if (curSum == sum){
                    res.add(oneAnswer(left,right));
                }
            }
            
            right++;// 右端点增加
            curSum += right;// 更新当前的和
        }
        // 将List<int[]> 转换成int[][]
        return res.toArray(new int[0][]);
    }


    /*
        方法2：简化计算
        1）等差数列求和公式
        2）二分查找法的变形
    */
    public int[][] FindContinuousSequence(int sum) {
        List<int[]> res = new ArrayList<>();
        if (sum < 3) {
            return res.toArray(new int[0][]);
        }
        
        int left = 1;
        int right = 2;
        while (right > left) {
            int curSum = (left+right)*(right-left+1)/2;// 快速求和
            if (curSum == sum) {
                res.add(oneAnswer(left,right));
                left++;
            } else if (curSum < sum) {
                right++;
            } else {
                left++;
            }
        }
        return res.toArray(new int[0][]);
    }


}
```

## 方法3：利用等差数列求和公式递推首相
已知等差数列的公差为1，和为s, 则设首相为x，项数为m:
$$
    \frac{(x + x + m - 1)m}{2} = s
$$
则：
$$
    x = \frac{2·s-m(m-1)}{2·m}
$$
我们从项数为1开始，枚举所有可能的元素个数，即可求出每一组的首相。
```Java
class Solution {
    // 返回一个解
    private int[] oneAnswer(int left,int right) {
        int[] ans = new int[right - left + 1];
        for (int i = 0;left <= right;i++,left++) {
            ans[i] = left;
        }
        return ans;
    }
    public int[][] findContinuousSequence(int s){
        List<int[]> res = new ArrayList<>();
        for(int m = 1;(2 * s - m * m + m) > 0;m++) {
            // 整数运算，求余数
            int remainder = (2 * s - m * m + m)%(2 * m);
            // 余数必须为0，表示x是整数
            if (remainder == 0 && m != 1) {
                int x = (2 * s - m * m + m)/(2 * m);
                res.add(oneAnswer(x,x+m-1));
            }
        }
        return res.toArray(new int[0][]);
    }

    //  计算优化
    public int[][] findContinuousSequence(int sum) {
        List<int[]> res = new ArrayList<>();
        int m = 2;
        int x0 = 2 * sum - m * m + m;
        while(x0 > 0) {
            int remainder = x0%(2 * m);
            if (remainder == 0) {
                int x = x0/(2 * m);
                res.add(0,oneAnswer(x,x+m-1));
            }
            m++;
            x0 = 2 * sum - m * m + m;
        }
        return res.toArray(new int[0][]);
    }
}
```