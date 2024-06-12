---
title: 两个链表的第一个公共结点
categories:
  - 剑指offer
tags:
- 链表
date: 2019-12-26 23:12:31
---

## 题目描述
输入两个链表，找出它们的第一个公共结点。

### 思路
- 如果两个链表有公共节点，那么者两个链表组成的形状是Y型的
- 我们可以考虑处理两个链表的非公共部分，舍弃长链表笔短链表长的部分
- 然后两个链表同时遍历，就可以遍历到公节点。

- 当然，暴力枚举也是可以试一下的
```cpp
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
输入两个链表，找出它们的第一个公共结点。


*/
class Solution {
public:
    unsigned int GetListLength(ListNode *pHead) {
        int length = 0;
        while (pHead != nullptr) {
            length++;
            pHead = pHead->next;
        }
        return length;
    }
    
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        // 非法判断
        if (pHead1 == nullptr || pHead2 == nullptr) {
            return nullptr;
        }
        
        // 得到两个链表的长度
        unsigned int nLength1 = GetListLength(pHead1);
        unsigned int nLength2 = GetListLength(pHead2);
        int nLengthDif = nLength1 - nLength2;
        
        // 长短链表交换
        ListNode* pListHeadLong = pHead1;
        ListNode* pListHeadShort = pHead2;
        if(nLength2 > nLength1)
        {
            pListHeadLong = pHead2;
            pListHeadShort = pHead1;
            nLengthDif = nLength2 - nLength1;
        }

        // 先在长链表上走两个链表差值的长度，再同时在两个链表上遍历
        for(int i = 0; i < nLengthDif; ++i)
            pListHeadLong = pListHeadLong->next;
        
        //  一起移动，直到到达第一个公共的节点
        while((pListHeadLong != nullptr) &&
            (pListHeadShort != nullptr) &&
            (pListHeadLong != pListHeadShort))
        {
            pListHeadLong = pListHeadLong->next;
            pListHeadShort = pListHeadShort->next;
        }

        // 得到第一个公共结点
        ListNode* pFisrtCommonNode = pListHeadLong;

        return pFisrtCommonNode;
    }
};
```