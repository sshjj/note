#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int _val):val(_val),next(NULL){}
};
ListNode* merge(ListNode* l1,ListNode* l2){
    ListNode* dummy = new ListNode(-1);
    ListNode* head = dummy;
    while(l1!=NULL && l2!=NULL){
        if(l1->val<=l2->val){
            head = l1;
            l1 =l1->next;
        }
        else{
            head = l2;
            l2 = l2->next;
        }
        head = head->next;
    }
    if(!l1)head = l1;
    if(!l2)head = l2;
    return dummy->next;

}
int main(){
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);

    p1->next = p2;
    p3->next = p4;
    ListNode* head  = merge(p1,p3);
    for(ListNode* q =head ;!q;q=q->next){
        cout<<q->val;
    }
    return 0;
}