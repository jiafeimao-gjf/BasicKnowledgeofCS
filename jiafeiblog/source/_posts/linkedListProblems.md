---
title: 链表题目集
categories:
  - 算法题集
tags:
  - 链表
date: 2019-12-25 23:54:30
---
```c++
#include <iostream>
#include <vector>
#include <string>
#include <stack>

#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

/**
 *
 * 节点数据结构
 */
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }

    /**
     * 默认的单链表数据：1->2->3->3->4->4->5
     * @return
     */
    ListNode* getList(){
        ListNode* p = new ListNode(1);
        p->next = new ListNode(2);
        p->next->next = new ListNode(3);
        p->next->next->next = new ListNode(3);
        p->next->next->next->next = new ListNode(4);
        p->next->next->next->next->next = new ListNode(4);
        p->next->next->next->next->next->next = new ListNode(5);
        return p;
    }
};
```
### 给定一个单链表的头节点head和一个元素节点nodeN，删除该节点nodeN，
```C++
/**
 * 要求算法时间复杂度为1，然后返回该链表的头节点
 * 弄清楚不同的情况，进行处理。综合的时间复杂度还是降低了。
 * n-1  个O(1) 和 1个O(n), 总的可以认为为O(1)
 */
class DeleteTheNode{
public:
    void deleteLinkedNode(ListNode** head,ListNode* nodeN){
        if (head == nullptr ||  nodeN == nullptr){
            return;
        }
        if (nodeN->next != nullptr){// 该节点不是尾节点，将本节点与后面的节点的值交换，删除后面的节点。主要
            ListNode* temp = nodeN->next;
            nodeN->val = temp->val;
            nodeN->next = temp->next;
            delete temp;
        } else if(*head == nodeN){// 该节点是头节点，直接删除，然后更新头节点
            // 直接删除
            delete nodeN;
            *head = (*head)->next;
        } else { // 该节点是链表的最后一个节点，遍历到最后，然后删除。该情况只有会出现一次，可以忽略
            ListNode* p = *head;
            while(p->next != nodeN){
                p = p->next;
            }
            p->next = nullptr;
            delete nodeN;
        }
    }
};
```
## 题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
```C++
/**
 * 删除单链表中重复的节点
 */

class Solution12{
public:
    // 参数为指向头节点指针的指针
    void deleteDuplicaiton(ListNode ** pHead){
        if (*pHead == nullptr){
            return;
        }
        ListNode * pre = nullptr;// 保存重复元素的上一个节点，保证不断链
        ListNode * p = *pHead;// 链表指针
        while(p != nullptr){// 遍历整个链表
            ListNode * pNext = p->next;// 记下下一个节点
            bool needDelete = false;
            if (pNext != nullptr && p->val == pNext->val) {// 判断是否重复
                needDelete = true;
            }
            if (!needDelete) {// 没有重复，更新前一个节点，和下一个节点
                pre = p;
                p = p->next;
            } else {
                int value = p->val;
                ListNode * t = p;
                while(t != nullptr && t->val == value){// 循环删除重复元素
                    pNext = t->next;
                    delete t;
                    t = pNext;
                }
                if (pre == nullptr){// 链表开头的重复节点
                    *pHead = pNext;
                } else {// 链表中间有重复节点
                    pre->next = pNext;
                }
                p = pNext;
            }
        }
    }

    // 头指针直接指向头节点
    void deleteDuplicaiton(ListNode * pHead){
        //printList(pHead);
        if (pHead == nullptr) return;

        ListNode* pre = nullptr;
        ListNode* p = pHead;
        ListNode* pNext = nullptr;
        while(p != nullptr){
            bool isDuplication = false;
            pNext = p->next;
            if (pNext != nullptr && p->val == pNext->val){
                isDuplication = true;
            }
            if (!isDuplication){
                pre = p;
                p = pNext;
            } else {// 元素重复了
                int val = p->val;
                ListNode * t = p;// 记录重复序列的后的第一个节点
                while(t != nullptr && t->val == val){// 循环删除重复节点
                    pNext = t->next;
                    delete t;
                    t = nullptr;

                    t = pNext;
                }
                if (pre == nullptr){// 头节点需更新
                    pHead = pNext;
                } else {
                    pre->next = pNext;
                }
            }
            p = pNext;
        }
    }
};
```
### 将两个单调非减序列合并，并保持两个元素的相对未知不变。非递归归并实现
```C++
class MergeList {
public:
    ListNode* merge(ListNode *pHead1, ListNode *pHead2)
    {
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        ListNode* p3 = new ListNode(0);

        // 特殊情况处理
        if (p1 == nullptr && p2 != nullptr) return p2;
        if (p2 == nullptr && p1 != nullptr) return p1;
        if (p1 == nullptr && p2 == nullptr) return nullptr;
        // 两个非空单增链表合并
        ListNode* head = p3;
        while (p1 != nullptr && p2 != nullptr){
            while(p2 != nullptr && p1->val > p2->val){
                p3->val = p2->val;
                p3->next = new ListNode(0);
                p3 = p3->next;
                p2 = p2->next;
            }
            while(p2 != nullptr && p1 != nullptr && p1->val <= p2->val){
                p3->val = p1->val;
                p3->next = new ListNode(0);
                p3 = p3->next;
                p1 = p1->next;
            }
        }
        while (p1 == nullptr && p2 != nullptr) {
            p3->val = p2->val;
            p2 = p2->next;
            if (p2 != nullptr){
                p3->next = new ListNode(0);
                p3 = p3->next;
            }else{
                p3->next = nullptr;
            }
        }
        while (p1 != nullptr && p2 == nullptr) {
            p3->val = p1->val;
            p1 = p1->next;
            if (p1 != nullptr){
                p3->next = new ListNode(0);
                p3 = p3->next;
            }else{
                p3->next = nullptr;
            }
        }
        return head;
    }
};
```
### 求两个链表的共同部分，并返回共同部分的头节点
 ```C++
class FindCommonNodePart{
    /**
     * 暴力循环求解 O(n^2)
     * @param pHead
     * @param qHead
     * @return
     */
    ListNode* findCommonNodePart1(ListNode *pHead,ListNode *qHead){
        ListNode* p = pHead;
        ListNode* q = qHead;
        if (p == nullptr || q == nullptr){
            return nullptr;
        }
        // 两个while循环，遍历求解
        while(p!=nullptr){
            q = qHead;
            while(q!=nullptr){
                if (q == p){
                    break;
                }
                q = q->next;
            }
            if (q == p){
                return q;
            }
            p = p->next;
        }
        return q;
    }

    /**
     * 根据相交链表的特点,O(len1+len2)
     * 先求两个链表的长度
     * 判断两个链表是否有公共部分
     * 若有，求出第一个公共的节点
     * @param pHead
     * @param qHead
     * @return
     */
    ListNode* findCommonNodePart2(ListNode *pHead,ListNode *qHead){
        ListNode* p = pHead;
        ListNode* q = qHead;
        ListNode* lastp = nullptr;
        ListNode* lastq = nullptr;
        if (p == nullptr || q == nullptr){// 任何一个链表为空，都无解
            return nullptr;
        }
        int len1 = 0,len2 = 0;
        while(p != nullptr){// 求链表p的长度
            ++len1;
            if (p->next == nullptr){
                lastp = p;
            }
            p = p->next;
        }
        while(q != nullptr){// 求链表q的长度
            ++len1;
            if (q->next == nullptr){
                lastp = q;
            }
            q = q->next;
        }
        if (lastp != lastq) {// 最后一个节点不同，则无解
            return nullptr;
        } else { // 否则必有解
            if (len1 > len2){// p链表比q链表长，p链表先向后移动len1-len2位
                p = pHead;
                q = qHead;
                while(len1!=len2){
                    len1--;
                    p = p->next;
                }
            } else { // 反之
                q = qHead;
                p = pHead;
                while (len2 != len1){
                    len2--;
                    q = q->next;
                }
            }
            while(p != q){// 两个链表同时向后移动，直到到达公共节点处
                p = p->next;
                q = q->next;
            }
        }
        return p;
    }

    /**
     * 使用栈，将两个全部压入两个栈，然后从结尾开始出栈，找到第一个相等的节点
     * @param pHead
     * @param qHead
     * @return
     */
    ListNode* findCommonNodePart3(ListNode *pHead,ListNode *qHead){
        stack<ListNode*> s1,s2;
        ListNode* p = pHead;
        ListNode* q = qHead;
        if (p == nullptr || q == nullptr) {
            return nullptr;
        }
        while (p != nullptr) {
            s1.push(p);
            p = p->next;
        }
        while (q != nullptr) {
            s2.push(q);
            q = q->next;
        }
        ListNode* common = nullptr;
        while (!s1.empty() && !s2.empty()) {// 同时出栈，直到达倒数第一个不同的节点
            if (s1.top() == s2.top()){
                common = s1.top();
                s1.pop();
                s2.pop();
            }else{
                break;
            }
        }
        return common;
    }

    /**
     * 将两个链表连接，将问题转化成链表是否有环的问题
     * @param pHead
     * @param qHead
     * @return
     */
    ListNode* findCommonNodePart4(ListNode *pHead,ListNode *qHead){
        
    }
};
```
## 题目描述
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
```C++
/**
 * 获取含有环的链表，环的入口节点
 */
class GetCircleStartNode{
private:
    /**
     * 子函数，用两个指针，一个快指针，一个慢指针，快指针必定会追上慢指针，可以获得环的入口
     * @param pHead
     * @return
     */
    ListNode* MeetingNode(ListNode * pHead){
        if (pHead == nullptr) {
            return nullptr;
        }

        ListNode* pSlow = pHead->next;
        if (pSlow == nullptr) {
            return nullptr;
        }

        ListNode* pFast = pSlow->next;
        while(pFast != nullptr && pSlow != nullptr){
            if (pFast == pSlow) {
                return pFast;
            }

            pSlow = pSlow->next;

            pFast = pFast->next;
            if (pFast != nullptr){
                pFast = pFast->next;
            }
        }

        return nullptr;
    }
public:
    ListNode* getCircleStartNode(ListNode* pHead){
        ListNode* meetingNode = MeetingNode(pHead);// 获得环的入口
        if (meetingNode == nullptr) return nullptr;

        // 求出环中节点的个数
        int nodesInLoop = 1;
        ListNode* pNode1 = meetingNode;
        while (pNode1->next != meetingNode) {
            pNode1 = pNode1->next;
            ++nodesInLoop;
        }

        // 环的入口节点为原来链表的倒数第nodesInLoop个节点，求环的入口节点
        pNode1 = pHead;
        for (int i = 0;i < nodesInLoop;++i) {
            pNode1 = pNode1->next;
        }

        ListNode* pNode2 = pHead;
        while (pNode1 != pNode2) {
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }
        return pNode1;
    }
};
```
### 复杂链表复制：
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
分析：
因为链表本身的连续性，所以，随机指针只是一个指针，目的是实现一个随机的下一个节点
随机下节点不需要复制。
```C++
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class CopyComplexList {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == nullptr) { // 是否为空链表
            return nullptr;
        }
        // 链表节点复制
        RandomListNode * currNode = pHead;
        while (currNode != nullptr) {
            RandomListNode *node = new RandomListNode(currNode->label);
            node->next = currNode->next;
            currNode->next = node;
            currNode = node->next;
        }
        // 链表随机节点处理，
        currNode = pHead;
        while (currNode != nullptr) {
            RandomListNode * node = currNode->next;     // 获取当前节点的复制节点
            if (currNode->random != nullptr) {          // 当前节点有随机下节点。
                node->random = currNode->random->next;  // 让随机下节点引用指向复制节点
            }
            currNode = node->next;// 跟新当前节点
        }
        // 新旧链表拆分，遍历一边，删除复制的节点。
        RandomListNode * pCloneHead = pHead->next;
        RandomListNode *tmp;
        currNode = pHead;
        while (currNode->next != nullptr) {
            tmp = currNode->next;        // 暂时存储引用复制节点
            currNode->next = tmp->next;  // 截断对复制节点的引用
            currNode = tmp;          //不仅原节点对复制节点的引用要截断，复制节点对原节点的引用也要截断
        }
        return pCloneHead;
    }
};
```