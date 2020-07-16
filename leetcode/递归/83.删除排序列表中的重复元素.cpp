//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)return head;
        head->next = deleteDuplicates(head->next);
        if(head->val == head->next->val){
            head = head->next;
        }
        return head;
    }
};