给定链表头结点 head，该链表上的每个结点都有一个 唯一的整型值 。

同时给定列表 G，该列表是上述链表中整型值的一个子集。

返回列表 G 中组件的个数，这里对组件的定义为：链表中一段最长连续结点的值（该值必须在列表 G 中）构成的集合。

示例 1：

输入: 
head: 0->1->2->3
G = [0, 1, 3]
输出: 2
解释: 
链表中,0 和 1 是相连接的，且 G 中不包含 2，所以 [0, 1] 是 G 的一个组件，同理 [3] 也是一个组件，故返回 2。

class Solution {
public:
    //题目意思：如果当前的节点在列表G中，并且下一个节点不在列表G中，我们就找到了一个组件的尾节点，将res加1
    int numComponents(ListNode* head, vector<int>& G) {
        set<int> record;
        for(int& g:G)record.insert(g);
        int res=0;
        ListNode *cur=head;
        while(cur)
        {   
            //cur在G中，逻辑或先检查前一个是否为真，前一个为真直接返回true，前一个为假在检查后一个是否为真
            //所以先判断cur的next是否空，为空则res++；若不为空，在判断cur的next是否在G中即可
            if(record.count(cur->val)&&(!cur->next||!record.count(cur->next->val)))
                res++;
            cur=cur->next;
        }
        return res;
    }
};