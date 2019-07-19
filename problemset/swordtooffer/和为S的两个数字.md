## 题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:
> 对应每个测试案例，输出两个数，小的先输出。

```C++
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        int lenght = array.size();
        // 二分查找❌，滑动窗口
        int a = 0;
        int b = lenght - 1;
        while (a < b){
            int curSum = array[a] + array[b];
            if (curSum == sum) {
                res.push_back(array[a]);
                res.push_back(array[b]);
                return res;
            } else if (curSum < sum){
                a++;
            } else {
                b--;
            }
        }
        return res;
    }
};
```