请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true

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
    bool isPalindrome(ListNode* head) {
        auto fast = head,slow = head;
        ListNode* pre = nullptr;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        while(slow){
            ListNode* p = slow->next;
            slow->next = pre;
            pre = slow;
            slow = p;
        }
        while(head && pre){
            if(head->val != pre->val)return false;
            head = head->next;
            pre = pre->next;
        }
        return true;
    }
};