给定一个二叉树

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return {};
        vector<int>res;
        queue<Node* >q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0;i<n;i++){
                auto t = q.front();
                q.pop();
                if(i!=n-1){
                    auto nex = q.front();
                    t->next = nex;
                }
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);                
            }
        }
        return root;
    }
};

//进阶
//你只能使用常量级额外空间。
//使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
class Solution {
public:
    Node* connect(Node* root) {
        Node* last = root;
        while(last!=NULL){
            while(last&&last->left == NULL && last->right ==NULL)last = last->next;
            if(last ==NULL)break;
            Node* cur = NULL;
            for(Node* i = last;i!=NULL;i = i->next){
                if(i->left){
                    if(cur!=NULL)
                        cur->next = i->left;
                    cur = i->left;
                }
                if(i->right){
                    if(cur!=NULL){
                        cur->next = i->right;
                    }
                    cur = i->right;
                }
            }
            last = last->left?last->left:last->right;
        }
        return root;
    }
};