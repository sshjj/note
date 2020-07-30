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
    ListNode* partition(ListNode* head, int x) {
        auto before = new ListNode(-1);
        auto p = before;
        auto after = new ListNode(-1);
        auto q = after;
        while(head!=nullptr){
            if(head->val < x){
                p->next = head;
                p = p->next;
            }
            else{
                q->next = head;
                q = q->next;
            }
            head = head->next;
        }
        q->next = nullptr;
        p->next = after->next;
        return before->next;
    }
};