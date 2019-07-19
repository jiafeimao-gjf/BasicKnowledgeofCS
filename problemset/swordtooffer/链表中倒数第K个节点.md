## 题目描述
输入一个链表，输出该链表中倒数第k个结点。
```C++
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* p = pListHead;
        ListNode* q = pListHead;
        int count = 0;
        // 非法判断
        if (k <= 0) return nullptr;
        // 统计链表节点数量
        while(count < k && p != nullptr){
            p = p->next;
            count++;
        }
        if (p == nullptr ){// 提前结束了节点
            if (count < k){// size < k,节点数量小于k
                return nullptr;
            }else {// size = k，节点数量恰好等于k
                return q;
            }
        } 
        // size > k，节点数量大于k，两个指针同时移动，直到到达倒数第k个节点
        while(p != nullptr){
            q = q->next;
            p = p->next;
        }
        return q;
    }
};
```