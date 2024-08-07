---
title: 替换空格
categories:
  - 剑指offer
tags:
  - 字符串
date: 2019-12-26 23:12:31
---

## 题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

### 解题思路：
- 借助两个游标，采用先统计总共的空间，
- 然后进行扫描，若是空格，则插入%20，不是就复制原始字符
- 空间：O(1)，时间：O(n)

```cpp
class Solution {
public:
    void replaceSpace(char *str,int length) {
        int count = 0;
        for (int i = 0; i < length;i++){
            if (str[i] == ' '){
                count++;
            }
        }
        char *p1 = (str + length);
        char *p2 = (str + length + 2*count);
        for (;p1>=str;p1--){
            if (*p1 == ' '){
                *p2-- = '0';
                *p2-- = '2';
                *p2-- = '%';
            } else{
                *p2-- = *p1;
            }
        }
    }
};
```