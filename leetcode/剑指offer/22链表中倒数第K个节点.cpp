```
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* cur = head;
        for(int i = 0;i<k;i++)cur = cur->next;
        while(cur){
            cur= cur->next;
            head = head->next;
        }
        return head;
    }
};
```