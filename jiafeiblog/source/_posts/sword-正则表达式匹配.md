---
title: 正则表达式匹配
categories:
  - 剑指offer
tags:
  - 正则表达式
date: 2019-12-26 23:12:31
---

## 题目描述
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 

在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配

### 解题思路
- 递归匹配，多重状态递归。
- “.” 匹配任意一个字符
- “*” 匹配0个或者多个前一个字符

```cpp
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        // 异常输入处理
        if (str == nullptr || pattern == nullptr){
            return false;
        }
        return matchCore(str,pattern);
    }
    
private:
    bool matchCore(char* str,char* pattern){
        if (*str == '\0' && *pattern == '\0') {// 模式匹配成功
            return true;
        }
        if (*str != '\0' && *pattern == '\0') {// 模式匹配失败
            return false;
        }
        
        if (*(pattern + 1) == '*'){ // 模式的第二个字符是*，可以有无数个
            // 匹配上了，或者可以匹配任意一个字符
            if (*pattern == *str || (*pattern == '.' && *str != '\0')){
                // 其实这里存在不合理的情况，一定会导致false，不过只要有一个true就行了
                return matchCore(str + 1,pattern + 2)   // 移动到下一个状态，且忽略*，*匹配0个字符
                    || matchCore(str + 1,pattern)       // 保持在当前模式状态
                    || matchCore(str,pattern + 2);      // .* 组合模式，忽略 *，*匹配0个字符
            } else { // 当前字符不匹配，且不是“.”
                return matchCore(str,pattern + 2);      //忽略 *，*匹配0个字符
            }
        }
        // 匹配上了，或者可以匹配任意一个字符
        if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
            return matchCore(str + 1,pattern + 1); // 都后移一位
        }
        return false;
    }
};
```