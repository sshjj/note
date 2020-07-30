递归三部曲：

1）找终止条件：本题终止条件很明显，当递归到链表为空或者链表只剩一个元素的时候，没得交换了，自然就终止了。
2）找返回值：返回给上一层递归的值应该是已经交换完成后的子链表。
3）单次的过程：因为递归是重复做一样的事情，所以从宏观上考虑，只用考虑某一步是怎么完成的。
我们假设待交换的俩节点分别为head和next，next的应该接受上一级返回的子链表(参考第2步)。
就相当于是一个含三个节点的链表交换前两个节点，就很简单了，想不明白的画画图就ok。

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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        auto nex = head->next;
        head->next = swapPairs(nex->next);
        nex->next = head;
        return nex;
    }
};

// 迭代

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        while(head!=NULL && head->next!=NULL){
            auto first = head;
            auto second = head->next;
            pre->next = second;
            first->next = second->next;
            second->next = first;

            pre = first;
            head = first->next;
        }
        return dummy->next;
    }
};