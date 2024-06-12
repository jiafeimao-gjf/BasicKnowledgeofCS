---
title: 把数组排成最小的数字
categories:
  - 剑指offer
tags:
  - 排序
date: 2019-12-23 23:08:33
---

## 题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

## 思路分析
- 探究比较器的设计和实现
- 排序运用

```cpp
class Solution {
    /*  
        本质是排序，需要自定义一个比较器  
    */
public:
    string PrintMinNumber(vector<int> numbers){
        string ret;
        vector<string> numbers_str;
        // 全部转换成字符串
        for(int i = 0; i < numbers.size(); ++i){
            numbers_str.push_back(to_string(numbers[i]));
        }
        // 排序
        sort(numbers_str.begin(), numbers_str.end(), MyCompare);
        // 结果处理
        for(int i = 0; i < numbers_str.size(); ++i)
            ret += numbers_str[i];
        return ret;
    }
private:
    // 比较器，利用string的运算符重载
    static bool MyCompare(const string &str1, const string &str2){
        return str1 + str2 < str2 + str1;
    }
};
```