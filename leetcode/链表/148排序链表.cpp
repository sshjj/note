在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
示例 2:

输入: -1->5->3->4->0
输出: -1->0->3->4->5

////归并排序

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* p=head;
        int length=0;
        while(p){
            length++;
            p=p->next;
        }
        for(int size=1;size<length;size<<=1)
        {
            ListNode* cur=dummy.next;//每次归并cur都从head节点开始
            ListNode* tail=&dummy;//tail主要用于连接每次归并后的链表
            while(cur){
                ListNode* left=cur;
                ListNode* right=cut(left,size);//将left切断，这样left有size个节点了，此时的right为后半部分的链表头
                cur=cut(right,size);//将right切断，这样right有size个节点了，此时的cur为后半部分的链表头

                tail->next=merge(left,right);//合并right和left
                while(tail->next){//保持tail为尾节点
                    tail=tail->next;
                }
            }
        }
        return dummy.next;
    }

    ListNode* cut(ListNode* head,int n)//将链表head的前n个节点切下来，然后返回后半部分的链表头
    {
        ListNode* p=head;
        while(--n&&p){
            p=p->next;
        }
        if(!p)return nullptr;
        ListNode* next=p->next;
        p->next=nullptr;
        return next;
    }

    ListNode* merge(ListNode* l1,ListNode* l2)//合并两个有序链表
    {
        ListNode dummy(0);
        ListNode* p=&dummy;
        while(l1&&l2){
            if(l1->val<l2->val){
                p->next=l1;
                p=l1;
                l1=l1->next;
            }
            else{
                p->next=l2;
                p=l2;
                l2=l2->next;
            }
        }
        p->next=l1?l1:l2;
        return dummy.next;
    }
};
