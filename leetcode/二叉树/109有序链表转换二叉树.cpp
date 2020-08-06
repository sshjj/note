给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int size =0;
        for(ListNode * l = head;l!=NULL;l=l->next)size++;
        return ListToBST(0,size-1,head);
    }
    TreeNode* ListToBST(int l,int r,ListNode* &head){
        if(l>r)return NULL;
        int mid = (l+r)/2;
        TreeNode* lt = ListToBST(l,mid-1,head);
        TreeNode* root = new TreeNode(head->val);
        root->left = lt;
        head = head->next;
        root->right = ListToBST(mid+1,r,head);
        return root;
    }
};

//
////


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildBST(head,nullptr);
    }
    TreeNode* buildBST(ListNode* head,ListNode* tail){
        if(head == tail)return NULL;
        ListNode* slow = head,*fast = head;
        while(fast !=tail && fast->next!=tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = buildBST(head,slow);
        root->right = buildBST(slow->next,tail);
        return root;
    }
};