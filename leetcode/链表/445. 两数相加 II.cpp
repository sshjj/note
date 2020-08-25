给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。


进阶：

如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

 

示例：

输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 8 -> 0 -> 7


题解：

题解1：首先利用反转链表将l1与l2进行反转，然后再利用两个链表之和的反转后的链表进行相加，最后将相加的结果反转就是最终答案了。
这个解法有些许繁琐，大家看题解2吧。
题解2：双栈法
将两个链表节点值全部压入栈中，然后每次去栈顶元素进行相加，因为这样保证了低位和低位相加，不会出现错位现象。最后直到两个栈为空且进位为0为止，就表示相加完成了。


//题解1代码
class Solution {
public:
    //题解1：本方法，先反转l1、l2，然后相加，最后返回相加的反转
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseList(l1);
        l2=reverseList(l2);
        return reverseList(addTwoNumbers(l1,l2));
    }
    
    //反转链表
    ListNode* reverseList(ListNode* head) {
        if(nullptr==head||nullptr==head->next)return head;
        ListNode *pre=nullptr,*cur=head;
        while(cur){
            ListNode *nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nxt;
        }
        return pre;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *head=new ListNode(0);//建立头结点
        ListNode *begin=head;
        int carry=0;//进位
        while(l1!=nullptr||l2!=nullptr||carry!=0)
        {
            //1、计算当前位的总和
            int sum=(l1?l1->val:0)+(l2?l2->val:0)+carry;

            //2、将个位数字生成一个新节点，并更新进位数字
            ListNode *temp=new ListNode(sum%10);
            carry=sum/10;

            //3、将temp加入到新链表中，并更新begin节点（begin相当于链表的尾节点，尾节点的next节点为空）
            begin->next=temp;
            begin=temp;

            //4、移动链表
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        return head->next;
    }
};


//题解2代码：双栈法
class Solution {
public:
	//题解2：双栈法，将链表的值全部压出栈中，然后遍历栈，进行相加，这样就能保证对应位进行相加并且不会错位了，最后循环退出到栈遍历完
    ListNode* addTwoNumbers_2(ListNode* l1,ListNode* l2){
        if(!l1||!l2)return l1?l1:l2;
        stack<int> s1,s2;
        while(l1){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2=l2->next;
        }
        int carry=0,t1,t2;
        //设置哑节点
        ListNode *dummy=new ListNode(0),*begin=nullptr;
        while(!s1.empty()||!s2.empty()||carry>0){
            t1=t2=0;
            if(!s1.empty()){t1=s1.top();s1.pop();}
            if(!s2.empty()){t2=s2.top();s2.pop();}
            carry+=t1+t2;
            //头插法将将新节点插入到dummy的后面
            begin=new ListNode(carry%10);
            begin->next=dummy->next;
            dummy->next=begin;
            carry/=10;
        }
        return dummy->next;
    }
};
