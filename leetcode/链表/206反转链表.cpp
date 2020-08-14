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
        if(head == NULL || head->next ==NULL)return head;
        ListNode* p =reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};