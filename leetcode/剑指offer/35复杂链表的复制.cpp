请实现 copyRandomList 函数，复制一个复杂链表。
在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        for(auto p = head;p;){
            auto np = new Node(p->val);
            auto next = p->next;
            p->next = np;
            np->next = next;
            p = next;
        }
        for(auto p= head;p;p = p->next->next){
            if(p->random)
                p->next->random = p->random->next;
        }
        auto dummy = new Node(-1);
        auto cur  = dummy;
        for(auto p = head;p;p=p->next){
            cur->next = p->next;
            cur = cur ->next;
            p->next = p->next->next;
        }
        return dummy->next;
    }
};