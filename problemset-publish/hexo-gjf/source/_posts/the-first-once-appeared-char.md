---
title: 第一个只出现一次的字符
categories:
  - 算法题集
tags:
  - 字符串
date: 2019-12-26 23:09:06
---
## 题目描述
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
```C++
class Solution {
public:
    /*在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
    并返回它的位置, 如果没有则返回 -1（需要区分大小写）.*/
    int FirstNotRepeatingChar(string str) {
        // 空字符串处理
        if (str.length() == 0){
            return -1;
        }
        // 遍历，求每个字符出现的频率
        int chars[127] = {0};
        for (int i = 0;i < str.length();++i){
            chars[str[i]]++;
        }
        // 遍历，求第一个只出现1次的字符
        for (int i = 0;i < str.length();++i){
            if (chars[str[i]] ==1){
                return i;
            }
        }
        // 不存在这样的字符
        return -1;
    }
};
```