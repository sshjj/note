输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

 
 /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* pre,*head;
    Node* treeToDoublyList(Node* root) {
        if(!root)return NULL;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
    void dfs(Node *cur){
        if(cur == nullptr)return ;
        dfs(cur->left);
        if(pre == nullptr)head = cur;
        else{
            pre->right = cur;
            cur->left = pre;
        }
        pre = cur;
        dfs(cur->right);
    }
};