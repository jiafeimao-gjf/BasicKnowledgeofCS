---
title: 一个字符串是否表示的是整数
categories:
  - 剑指offer
tags:
  - 正则表达式
date: 2019-12-25 23:54:30
---
## 题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

## 思路分析
- 指针操作 
- 数字表示解析
    - 一般数字
    - 科学表达式

```cpp
class Solution {
public:
    bool isNumeric(char* string)
    {
        if (string == nullptr) {
            return false;
        }
        
        bool numberic = scanInteger(&string);//整数部分
        
        if (*string == '.') {// 小数部分
            ++string;
            
            numberic = scanUnsignedInteger(&string) || numberic;
        }
        
        if (*string == 'e' || *string == 'E') {// 指数部分
            ++string;
            
            numberic = numberic && scanInteger(&string);
        }
        
        return numberic && *string == '\0';
    }
private:
    /**
        子函数，扫描整数
    */
    bool scanInteger(char** str){
        // 符号处理
        if (**str == '+' || **str == '-'){
            ++(*str);
        }
        // 处理无符号整数
        return scanUnsignedInteger(str);
    }
    /**
        子函数，扫描无符号整数
    */
    bool scanUnsignedInteger(char** str){
        const char* before = *str;
        // 满足无符号整数要求
        while(**str != '\0' && **str >= '0' && **str <= '9'){
            ++(*str);// 指针后移
        }
        
        return *str > before;// 是否存在数字
    }

};
```