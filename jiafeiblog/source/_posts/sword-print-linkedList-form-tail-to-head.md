---
title: 从尾到头打印链表
categories:
  - 剑指offer
tags:
  - 链表
date: 2019-12-26 23:07:35
---
## 题目描述
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
### vector 的函数列表
（1）a.assign(b.begin(), b.begin()+3); //b为向量，将b的0~2个元素构成的向量赋给a  
（2）a.assign(4,2); //是a只含4个元素，且每个元素为2  
（3）a.back(); //返回a的最后一个元素  
（4）a.front(); //返回a的第一个元素  
（5）a[i]; //返回a的第i个元素，当且仅当a[i]存在2013-12-07  
（6）a.clear(); //清空a中的元素  
（7）a.empty(); //判断a是否为空，空则返回ture,不空则返回false  
（8）a.pop_back(); //删除a向量的最后一个元素  
（9）a.erase(a.begin()+1,a.begin()+3); //删除a中第1个（从第0个算起）到第2个元素，也就是说删除的元素从a.begin()+1算起（包括它）一直到a.begin()+3（不包括它）  
（10）a.push_back(5); //在a的最后一个向量后插入一个元素，其值为5  
（11）a.insert(a.begin()+1,5); //在a的第1个元素（从第0个算起）的位置插入数值5，如a为1,2,3,4，插入元素后为1,5,2,3,4  
（12）a.insert(a.begin()+1,3,5); //在a的第1个元素（从第0个算起）的位置插入3个数，其值都为5  
（13）a.insert(a.begin()+1,b+3,b+6); //b为数组，在a的第1个元素（从第0个算起）的位置插入b的第3个元素到第5个元素（不包括b+6），如b为1,2,3,4,5,9,8         ，插入元素后为1,4,5,9,2,3,4,5,9,8  
（14）a.size(); //返回a中元素的个数；  
（15）a.capacity(); //返回a在内存中总共可以容纳的元素个数  
（16）a.resize(10); //将a的现有元素个数调至10个，多则删，少则补，其值随机  
（17）a.resize(10,2); //将a的现有元素个数调至10个，多则删，少则补，其值为2  
（18）a.reserve(100); //将a的容量（capacity）扩充至100，也就是说现在测试a.capacity();的时候返回值是100.这种操作只有在需要给a添加大量数据的时候才         显得有意义，因为这将避免内存多次容量扩充操作（当a的容量不足时电脑会自动扩容，当然这必然降低性能）   
（19）a.swap(b); //b为向量，将a中的元素和b中的元素进行整体性交换  
（20）a==b; //b为向量，向量的比较操作还有!=,>=,<=,>,<  
```cpp 
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> array;
        while(head != 0){
            // 头插法反转链表
            array.insert(array.begin(),head->val);// 调用vector的方法insert，将目标节点插入到vector头节点之前
            head = head->next;
        }
        return array;
    }
};
```