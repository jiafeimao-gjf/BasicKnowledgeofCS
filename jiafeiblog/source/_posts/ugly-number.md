---
title: 丑数
date: 2019-12-17 09:38:33
categories:
- 剑指offer
tags:
- 动态规划
---
# 263、丑数判断
编写一个程序判断给定的数是否为丑数。

丑数就是只包含质因数 2, 3, 5 的正整数。

### 示例 1:
```
输入: 6
输出: true
解释: 6 = 2 × 3
```
### 示例 2:
```
输入: 8
输出: true
解释: 8 = 2 × 2 × 2
```
### 示例 3:
```
输入: 14
输出: false 
解释: 14 不是丑数，因为它包含了另外一个质因数 7。
```
- 说明：
    - 1 是丑数。
    - 输入不会超过 32 位有符号整数的范围: [−231,  231 − 1]。

<!-- 
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ugly-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 -->

## 代码
```java
class Solution {
    public boolean isUgly(int num) {
        if (num == 0) return false;
        while(num%2==0) num /= 2;
        while (num%3==0) num /= 3;
        while(num%5==0) num /= 5;
        return num == 1;
    }
}
```
# 264、找到第n个丑数
编写一个程序，找出第 n 个丑数。

丑数就是只包含质因数 2, 3, 5 的正整数。

### 示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。

- 说明:  
  - 1 是丑数。
  - n 不超过1690。

<!-- 来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ugly-number-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 -->

## 动态规划
- dp[i] 第i小的丑数 
- $$ dp(i) = min(dp(t2)*2,min(dp(t3)*3,dp(t5)*5)) $$
## 代码
```java
class Solution {
    public int nthUglyNumber(int n) {
        // 1, 2, 3, 4, 5, 6, 8, 9, 10, 12
        if (n < 7) return n;// 前6个丑数，
        int[] dp = new int[n];
        dp[0] = 1;
        // 初始化为0,因为一开始没有2,3,5的倍数
        int t2 = 0,t3 = 0,t5 = 0;
        for (int i = 1;i < n;i++) {
            // 获得最小的第i个丑数，双重最小值
            dp[i] = Math.min(dp[t2]*2,Math.min(dp[t3]*3,dp[t5]*5));
            // 谁是最小的第i个丑数
            // i = 1的时候，都加1
            if (dp[i] == dp[t2] * 2) t2++;
            if (dp[i] == dp[t3] * 3) t3++;
            if (dp[i] == dp[t5] * 5) t5++;
        }
        return dp[n - 1];
    }
}
```