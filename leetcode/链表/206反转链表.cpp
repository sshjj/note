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
    ListNode* reverseList(ListNode* head) {
        if(!head)return NULL;
        auto p = head,q = head->next;
        while(q){
            ListNode* nex = q->next;
            q->next = p;
            p = q;
            q= nex;    
        }
        head->next = NULL;
        return p;
    }
};