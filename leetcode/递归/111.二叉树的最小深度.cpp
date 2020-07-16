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
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if(!root->left || !root->right)return l+r+1;
        else return min(l,r)+1;
    }
};

//迭代
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1)return t2;
        stack<pair<TreeNode* ,TreeNode* >>stk;
        if(t1&&t2)stk.push(make_pair(t1,t2));
        while(stk.size()){
            pair<TreeNode*,TreeNode*>cur = stk.top();stk.pop();
            cur.first->val = cur.first->val+cur.second->val;
            if(cur.second->left){
                if(!cur.first->left)cur.first->left = new TreeNode(0);
                stk.push(make_pair(cur.first->left,cur.second->left));
            }
            if(cur.second->right){
                if(!cur.first->right)cur.first->right = new TreeNode(0);
                stk.push(make_pair(cur.first->right,cur.second->right));
            }
        }
        return t1;
    }
};