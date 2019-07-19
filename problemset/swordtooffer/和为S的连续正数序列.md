## 题目描述
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
输出描述:
> 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

```C++
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
    /*
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
    */
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