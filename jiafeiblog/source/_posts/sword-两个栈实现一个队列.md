---
title: 两个栈实现一个队列
categories:
  - 剑指offer
tags:
  - 栈
  - 队列
date: 2019-12-26 23:12:31
---

## 题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

### 思路
- 一个栈stack1专门负责入队，一个栈是stack2专门用于出队
- 出队的时候，将入队栈中的元素全部压入出队栈，这样出队栈的pop()就等价于队列的pop()
```cpp
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.size() == 0){
            while(stack1.size() > 0){
                int item = stack1.top();
                stack1.pop();// pop没有返回值
                stack2.push(item);
            }
        }
        int res = stack2.top();
        stack2.pop();// 先top()获得栈顶元素，再调用pop()弹出栈顶元素
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
```