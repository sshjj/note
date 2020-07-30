题解1：分治法
k个链表利用二分为k个独立的子链表，然后两两组合，最后合并成k个排序链表
时间复杂度：O(nlogk)，n为单个链表的长度，k表示k个链表


题解2：优雅的暴力法
利用队列queue来实现两两链表的组合，首先将队列前两个链表合并成一个，然后添加到队列的尾部，直到队列中只有一个链表时，表示k个链表已经合成了。

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return nullptr;
        return merge(lists,0,lists.size()-1);
    }
    ListNode* merge(vector<ListNode*>& lists,int l,int r){
        if(l == r)return lists[l];
        int mid = (l+r)>>1;
        ListNode* l1 = merge(lists,l,mid);
        ListNode* l2 = merge(lists,mid+1,r);
        return mergeTwoLists(l1,l2);
    }
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
        if(l1 ==NULL)return l2;
        if(l2 == NULL)return l1;
        ListNode *head;
        if(l1->val<l2->val){
            head = l1;
            head->next = mergeTwoLists(l1->next,l2);
        }
        else {
            head = l2;
            head->next = mergeTwoLists(l1,l2->next);
        }
        return head;
    }
};