/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

题解：
思路：设链表A的长度为a+c，链表B的长度为b+c，a为链表A不公共部分，b为链表B不公共部分，c为链表A、B的公共部分，
将两个链表连起来，A->B和B->A，长度：a+c+b+c=b+c+a+c，若链表AB相交，则a+c+b与b+c+a就会抵消，它们就会在c处相遇；
若不相交，则c为nullptr，则a+b=b+a，它们各自移动到尾部循环结束，即返回nullptr


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)return nullptr;
        auto a  = headA,b = headB;
        while(a!=b){
            
            if(a)a=a->next;
            else a = headB;
            if(b)b = b->next;
            else b = headA;
        }
        return a;
    }
};