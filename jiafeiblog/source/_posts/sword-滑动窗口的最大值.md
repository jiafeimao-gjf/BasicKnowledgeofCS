---
title: 滑动窗口的最大值
categories:
  - 剑指offer
tags:
  - 滑动窗口
date: 2019-12-26 23:12:31
---

## 题目描述
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

### 思路
- 一个固定大小的窗口，在数组中滑动，找出所有窗口中数值大的
- 用队列存储求最大值的下标

PS 感觉这道题直接遍历一遍求最大值不就行了吗？？？？？？想什么呢？？是记录每一个滑动窗口的最大值
```cpp
//deque s中存储的是num的下标
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        deque<int> s;
        for(unsigned int i=0;i<num.size();++i){
            //从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
            while(s.size() && num[s.back()] <= num[i]) {
                s.pop_back();
            }
            //当当前窗口移出队首元素所在的位置，即队首元素坐标对应的num不在窗口中，需要弹出
            while(s.size() && i - s.front() + 1 > size) {
                s.pop_front();
            }
            s.push_back(i);//把每次滑动的num下标加入队列
            if(size && i + 1 >= size)//当滑动窗口首地址i大于等于size时才开始写入窗口最大值
                res.push_back(num[s.front()]);
        }
        return res;
    }
};
```