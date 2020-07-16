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
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        else 
            return isBalanced(root->left) && isBalanced(root->right)&& abs(hight(root->left)-hight(root->right))<=1;
    }
    int hight(TreeNode* p){
        if(!p)return 0;
        int res  = 0;
        int l = hight(p->left);
        int r = hight(p->right);
        res = max(l,r)+1;
        return res;
    }
};