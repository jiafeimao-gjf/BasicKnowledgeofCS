---
title: 翻转单词顺序列
categories:
  - 剑指offer
tags:
  - 字符串
date: 2019-12-26 23:12:31
---

## 题目描述
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

### 思路分析
- 遍历一遍，记录每个单词
- 每个单词记录后，插入到结果的前面

```cpp
class Solution {
public:
    string ReverseSentence(string str) {
        string res = "", tmp = "";
        for(unsigned int i = 0; i < str.size(); ++i){
            // 遇到空格，将单词插入到字符串前面，重置单词
            if(str[i] == ' ') res = " " + tmp + res, tmp = "";
            // 记录单词
            else tmp += str[i];
        }
        // 最后一个单词
        if(tmp.size()) res = tmp + res;
        return res;
    }
};
```