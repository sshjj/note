/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
如果 pos 是 -1，则在该链表中没有环。



class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)return false;
        auto first  = head,second = head->next;
        while(first!=second){
            if(!second || !second->next)return false;
            first = first->next;
            second = second->next->next;
        }
        return true;
    }
};