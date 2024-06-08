---
title: 5、longestPalindoemeSubstring
categories:
- leetcode
tags:
  - null
date: 2020-07-26 00:19:44
---

# 5、最长回文子串的
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

> 链接：https://leetcode-cn.com/problems/longest-palindromic-substring

## 1、求解方法——时间复杂度 空间复杂度
* 暴力枚举——O（n^3）O（1）
* 中点扩展法——O（n^2）O（1)
* 动态规划法——O（n^2）O（n^2）
* manacher算法——O（n） O（n）
## 2、测试用例
* null
* a
* aaa
* aabcdfdc
* asdfgfdsa
* asafghjjhgf
* asafghjjjhgfklp
# 3、具体解法代码——C++实现 c++14
## 3.1 暴力枚举
* 第一步：枚举出所有可能的子串
* 第二步：判断各个子串是否是回文串
* 第三步：如果是回文串，更新最大的回文子串的长度
### 代码：
```c++
/**
 * 子函数：判断该子串是否是回文串
 */
bool isPalindrome(const char *str, int begin, int end){
    bool is = true;
    // 双指针，逐渐向中间逼近检查是否回文
    while(begin <= end){
        if (str[begin] == str[end]) {
            begin++;
            end--;
        } else {
            is = false;
            break;
        }
    }
    return is;
}

/**
 * 主函数：特殊情况处理以及暴力枚举所有子串，并判断是否是回文串
 */
int longestPalindrome(const char *str){
    if (str == nullptr) {
        return 0;
    }
    int len = strlen(str);
    if (len == 1) {
        return 1;
    }
    int longest = 1;
    // 双层循环，枚举所有的子串
    for (int i = 0;i < len; ++i) {
        for (int j = i+1;j < len; ++j) {
            if (isPalindrome(str, i, j)) {
                longest = longest < j - i + 1 ? j - i + 1:longest;
            }
        }
    }
    return longest;
}
```
## 3.2 中点扩展法
* 第一步：遍历所有的字符位置i
* 第二步：求出以i为中心的回文串的长度
* 第三步：更新最大的回文子串的长度
#### 代码：
### C++版
```c++
// 由中心进行扩展，找出最长的回文串，要考虑偶数回文、和奇数回文
int palindrome(const char *str, int mid){
    // 默认奇数回文
    int left = mid - 1;
    int right = mid + 1;
    // 最开始元素相同处理，偶数回文处理
    if (str[mid] == str[left] && str[mid] != str[right]){
        left--;
    } else {
        if (str[mid] != str[left] && str[mid] == str[right]) {
            right++;
        }
    }
    // 中心扩展
    int len =  strlen(str);
    while(left >= 0 && right <= len - 1 && str[left] == str[right]) {
        left--;
        ++right;
    }
    // 返回回文串的长度
    return right - left - 1;
}

int longestPalindrome(const char *str){
    if (str == nullptr) {
        return 0;
    }
    int len = strlen(str);
    if (len == 1) {
        return 1;
    }
    // 遍历每一个位置，进行中心扩展
    int longest = 1;
    for (int i = 0; i < len; ++i) {
        int length = palindrome(str,i);
        if (longest < length) {
            longest = length;
        }
    }

    return longest;
}
```
## Java版
```java
class Solution {
    public String longestPalindrome(String s) {
        // 特殊情况处理
        if (s == "" || s.length() < 1) { return "";}
        // 左右指针
        int start = 0,end = 0;
        for (int i = 0;i < s.length(); i++) {
            // 求i处的回文串的长度
            int len1 = expandAroundCenter(s,i,i); // 奇数回文
            int len2 = expandAroundCenter(s,i,i+1);// 偶数回文
            int len = Math.max(len1,len2);// 取最优
            // 更新最长回文字串的区间
            if (len > end - start) {
                start = i - (len - 1)/2;// 中间点减去一半的长度，字串的开始
                end = i + len / 2;// 字串的结束
            }
        }
        return s.substring(start,end + 1);
    }
    // 子函数，实现中心扩展求最长的回文串
    private int  expandAroundCenter(String s,int left,int right) {
        int L = left;
        int R = right;
        while(L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) {
            L--;
            R++;
        }
        return (R-L-1);
    }
}
```

## 3.3 动态规划
* 第一步：初始化辅助数组p[len][len]，每个字符本身是长度为1的回文串，相邻两个相等的字符也是长度为1的回文串
    * p[i][j] = 1，表示j-1~i+1的子串是回文串
    * p[i][j] = 0，表示j-1~i+1的子串不是回文串
* 第二步：枚举所有可能的子串，利用辅助数组，进行快速求解最长回文子串的长度
* 第三步：更新最大的回文子串的长度
### 代码：
```c++
int longestPalindrome3(const char *str) {
    if (str == nullptr) {
        return 0;
    }
    int len = strlen(str);
    if (len == 1) {
        return 1;
    }

    int dp[100][100];   // 状态数据，数组大小可以更具题目的字符串大小来设置
    // 初始化最初的状态
    for (int i = 0;i < len - 1; ++i) {
        dp[i][i] = 1;
        if (str[i] == str[i + 1]) {
            dp[i][i+1] = 1;
        }
    }
    int longest = 1;
    // 动态规划求解问题
    for (int i = 0;i < len; ++i) {
        for (int j = i + 2;j <= len; ++j) {
            if (str[i] == str[j]) {     // 满足边界断点回文
                dp[i][j] = dp[i][j-1];  // 依据之前的结果判断，更新新的子串是否为回文串
                if (dp[i][j] == 1) {    // 是回文串
                    int tmp = j - i + 1;
                    if (longest < tmp) {    // 更新最大回文串的长度
                        longest = tmp;
                    }
                }
            }
        }
    }

    return longest;
}
```
## 3.4 manacher算法
* 第一步：对原来的串进行预处理，插入辅助字符#，将其转化成一个只有奇数长度的回文子串的字符串
* 第二步：利用辅助空间p[n]，变量mx和id，遍历字符串。
    * p[i]表示处理过的字符串的第i位的回文串长度
    * mx表示当前的最长的回文串的左边界
    * id表示当前的最长的回文串的中间字符索引
* 第三步：遍历过程描述，对于第i个字符
    * 先确定p[i]的值
    * 扩展回文串，更新p[i]的值
    * 更新mx和id
    * 更新最长的子串的长度
### 代码：
```c++
int longestPalindrome(const char *str) {
        if (str == nullptr) return 0;

        int len = strlen(str);
        if (len == 1) return 1;
        // 预处理，将待求的回文串的长度为奇数
        char *tmp = new char[2*len + 3];
        tmp[0] = '@';
        for (int i = 1;i < 2*len; i += 2) {
            tmp[i] = '#';
            tmp[i+1] = str[i / 2];
        }
        tmp[2 * len + 1] = '#';
        tmp[2 * len + 2] = '@';
        tmp[2 * len + 3] = 0;
        cout<<"tmp = "<<tmp<<endl;

        len = strlen(tmp);
        cout<<"len = "<<len<<endl;
        int mx = 0,id = 0;// mx=id+P[id]，即回文子串的边界，id表示最大回文子串中心的位置
        int p[1000];// 辅助数组，p[i]表示i处的字符的回文串的长度的一半
        memset(p,0,1000);
        int longest = 0;
        for (int i = 1;i <= len-2; ++i){ // 遍历求解
            // 求出p[i]的值
            if (mx >= i) {// 已存在对称的子串
                p[i] = min(p[2*id-i],mx-i);// 更新
            } else {
                p[i] = 1;// 初始化为1
            }
            cout<<"扩展前：p["<<i<<"] = "<<p[i]<<endl;
            while (tmp[i + p[i]] == tmp[i - p[i]]) {// 回文半径扩张,类似于中心扩展法
                ++p[i];
            }
            cout<<"扩展后：p["<<i<<"] = "<<p[i]<<endl;
            if (p[i] + i > mx) {// 更新最远边界和最大的回文子串的位置
                mx = p[i] + i;
                id = i;
            }
            cout<<"mx = "<<mx<<",id = "<<id<<endl;
            longest = max(longest,p[id]);// 更新最大值
        }
        delete[] tmp;
        return longest - 1;
    }
```


