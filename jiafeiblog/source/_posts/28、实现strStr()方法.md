---
title: 28、实现strStr()方法
categories:
- leetcode
tags:
  - null
date: 2020-07-26 00:19:44
---


### Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

#### Example 1:

> Input: haystack = "hello", needle = "ll"
> Output: 2
#### Example 2:

> Input: haystack = "aaaaa", needle = "bba"
> Output: -1
- Clarification:

> What should we return when needle is an empty string? This is a great question to ask during an interview.

> For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

<!-- 来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-strstr
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 -->
### 原理看[链接](https://blog.csdn.net/v_july_v/article/details/7041827)
### 代码
- 暴力破解,O(M*N)
```cpp
int strStr(string haystack, string needle) {
        if (haystack.length() == 0 && needle.length() != 0) return -1;
        if (needle.length() == 0) return 0;
        int res = -1;
        int len1 = haystack.length();
        int len2 = needle.length();
        for(int i = 0;i < len1 && len1 - i >= len2; ++i) {// len1 - i >= len2 不满足就没有搜索的必要了
            if (haystack[i] == needle[0]){
                int j = 1;
                while(j < len2 && haystack[i+j] == needle[j]) { // 字符匹配
                    j++;
                }
                if (j == len2) {
                    res = i;
                    break;
                }
            }
        }   
        return res;
    }
```
- 优雅的一次遍历，但是没有优化，最后长度不足的时候，可以直接退出。O(M*N)
```cpp
int strStr(string haystack, string needle) {
    if (needle.empty()) {
        return 0;
    }
    int i = 0,j = 0;
    int len1 = haystack.length();
    int len2 = needle.length();
    while(haystack[i]!='\0' && needle[j] != '\0') {
        if (haystack[i] == needle[j]) {
            if (j == 0 && len1 - i < len2) break; // 优化
            i++;
            j++;
        } else {// 还原，从头开始
            i = i - j + 1;
            j = 0;
        }
    }
    if (needle[j] == '\0') {// 找到解了
        return i - j;
    }
    return  -1;
}
```
- 函数库解法
```cpp
int strStr(string haystack,string needle) {
    if (needle.empty()) {return 0;}
    int pos = haystack.find(needle);
    return pos;
}
```
- KMP 解法 O(M+N)
- 智能回溯，较少无用的遍历
```cpp
// getNext函数，构建有限状态机
vector<int> getNext(string str) {
    int len = str.size();

    vector<int> next;
    next.push_back(-1);

    int j = 0,k = -1;
    while (j < len - 1){
        if (k == -1 || str[k] == str[j]) {// 出现重复字符
            j++;
            k++;
            next.push_back(k);
        } else {
            k = next[k];// 字符不重复，返回
        }
    }
    return next;
}
int strStr(string haystack,string needle) {
    if (needle.empty()) {return 0;}

    int i = 0,j = 0;
    int len1 = haystack.size();
    int len2 = needle.size();

    vector<int> next;
    next = getNext(needle);
    while (i < len && j < len2) {
        if ((j == -1) || (haystack[i] == needle[j])) {
            i++;
            j++;
        } else {
            j = next[j];// 获取下一个位置，i的位置不需要动
        }
    }
    if (j == len2) {
        reurn i - j;
    }
    return -1;
}
// getNext优化，当字符失配时，回到相同字符无意义，应继续递归
vector<int> getNext(string str) {
    int len = str.size();

    vector<int> next;
    next.push_back(-1);

    int j = 0,k = -1;
    while (j < len - 1){
        if (k == -1 || str[k] == str[j]) {// 出现重复字符
            j++;
            k++;
            if  (str[j] != str[k]) {next.push_back(k);}
            else { next.push_back(next[k]); }
        } else {
            k = next[k];// 字符不重复，返回
        }
    }
    return next;
}
```
- BM 算法，时间复杂度最差和KMP一样 最佳是O(n)O(n)
```cpp
// 创建坏字符集
void get_bmB(string& T,vector<int>& bmB){
    int tlen = T.size();
    // 初始化
    for (int i = 0;i < 256;i++) {
        bmB.push_back(tlen);
    }
    // 更新
    for (int i = 0;i < tlen - 1;i++) {
        bmB[T[i]] = tlen-i-1;
    }
}

void get_suff(string& T,vector<int>& suff) {
    int tien = T.size();
    int k;
    for (int i = tlen - 2; i >= 0;i--) {
        k = i;
        while (k >= 0 && T[k]==T[tlen-1-i+k]) {
            k--;
        }
        suff[i] = i - k;
    }
}

void get_bmG(string& T,vector<int>& bmG) {
    int i,j;
    int tlen = T.size();
    vector<int> suff(tlen + 1,0);
    get_suff(T,suff);// suff存储字串的最长匹配长度
    // 初始化，当没有好后缀也没有公共前缀时
    for (i = 0;i < tlen; ++i) {
        bmG[i] = tlen;
    }
    // 没有好后缀，有公共前缀，调用suff, 但是要右移一位 类似KMP里的next数组
    for (i = tlen - 1;i >= 0;i--) {
        if (suff[i] == i + 1) {
            for (j = 0;j < tlen - 1;j++) {
                if (bmG[j] == tlen) { // 保证每个位置不会重复修改
                    bmGp[j] = tlen - 1 - i;
                }
            }
        }
    }
    // 有好后缀 有公共前缀
    for (i = 0;i < tlen -1;i++) {
        bmG[tlen-1-suff[i]]= tlen - 1 - i;// 移动距离
    }

}

int strStr(string haystack,string needle) {
    int i = 0,j = 0;
    int tlen = needle.size();
    int slen = haystack.size();

    vector<int> bmG(tlen,0);
    vector<int> bmB;
    get_bmB(needle,bmB);
    get_bmG(needle,bmG);

    while (i <= slen - tlen) {// 优化
        for (j = tlen - 1;j > -1&& haystack[i + j] == needle[j];j--);
        if (j == (-1)) { return i;}
        i += max(bmG[j],bmB[haystack[i+j]] - (tlen - i - j));
    }

    return -1;
}
```
- Sunday 时间复杂度:
- 最坏为O(M*N)O(M∗N) 平均复杂度为O(N)O(N)

```cpp
int strStr(string haystack,string needle) {
    if (needle.empty()) { return 0;} 
    
    int slen = haystack.size();
    int tlen = needle.size();

    int i = 0,j = 0;// i 指向源串首位，j指向字串首位
    int k;
    int m = tlen;// when first match, 源串中参与匹配的元素的下一位

    for (;i < slen;) {
        if (haystack[i] != needle[j]) {
            for (k = tlen - 1;k >= 0;k--) {// 遍历查找此时字串与源串[i + tlen + 1]相等的最右位置
                if (needle[k] == haystack[m]) {
                    break；
                }
            }
            i = m - k;// 更新下一次匹配源串开始首位，跳过已匹配的相同部分串
            j = 0;// j更新为字串的首位
            m = i + tlen;// m为 下一次参与匹配的源串最后一位元素的下一位
            if (m > slen) { // 当下一次参与匹配的源串子树的最后一位的下一位超过源串长度时
                return -1;
            }
        } else  {
            if (j == tlen-1) {// 匹配成功
                return i - j;
            }
            i++;
            j++;
        }
    }
    return -1;
}
```