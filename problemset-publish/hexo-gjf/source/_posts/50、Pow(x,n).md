---
title: 50、Pow(x,n)
categories:
- leetcode
tags:
  - null
date: 2020-07-26 00:19:44
---

实现 pow(x, n) ，即计算 x 的 n 次幂函数。

### 示例 1:

- 输入: `2.00000, 10`
- 输出: `1024.00000`
### 示例 2:

- 输入: 2.10000, 3
- 输出: 9.26100
### 示例 3:

- 输入: 2.00000, -2
- 输出: 0.25000
> 解释: 2-2 = 1/22 = 1/4 = 0.25

**说明:**

- 100.0 < x < 100.0
- n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。

<!-- 来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/powx-n
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 -->

# 题解
## 1、暴力计算
- 时间 $O(n)$
- 空间 $O(1)$
```java
class Solution {
    public double myPow(double x, int n) {
        long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;
        for (long i = 0; i < N; i++)
            ans = ans * x;
        return ans;
    }
};
```
## 2、快速幂
- 时间 $O(log(n))$
- 空间 $O(1)$
- 循环实现
```java
class Solution {
    public double myPow(double x, int n) {
        long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double res = 1;
        double base = x;
        for (long i = N;i > 0;i/=2) {
            if (i % 2 == 1) {
                res = res * base;
            }
            base = base * base;
        }
        
        return res;
    }
}
```

- 递归实现
```java
class Solution {
    private double fastPow(double x, long n) {
        if (n == 0) {
            return 1.0;
        }
        double half = fastPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }

        // return n % 2 == 0 ? half * half : half * half * x;
    }
    public double myPow(double x, int n) {
        long N = n;
        // 负指数幂
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return fastPow(x, N);
    }
};
```