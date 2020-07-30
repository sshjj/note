给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

示例：

给你这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5
//递归方法 + 反转链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr)return head;
        auto a = head,b = head;
        for(int i = 0;i<k;i++){
            if(b == nullptr)return head;
            b = b->next;
        }
        auto dummy = reverse(a,b);
        a->next = reverseKGroup(b,k);
        return dummy;
    }
    ListNode* reverse(ListNode* a,ListNode* b){
        ListNode* pre = nullptr , *cur = a ;
        while(cur!= b){ 
            auto nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
};