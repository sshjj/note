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
    pair<ListNode*,ListNode*>myReverse(ListNode* head,ListNode* tail){
        ListNode* prev = tail->next;
        ListNode* p = head;
        while(prev!= tail){
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail,head};

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;
        while(head){
            ListNode* tail = pre;
            for(int i = 0;i<k;++i){
                tail = tail->next;
                if(!tail){
                    return hair->next;
                }
            }
            ListNode* nex = tail->next;
            pair<ListNode*,ListNode*>result = myReverse(head,tail);
            head = result.first;
            tail = result.second;
            pre->next= head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }
        return hair->next;
    }
};