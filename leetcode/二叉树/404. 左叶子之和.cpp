计算给定二叉树的所有左叶子之和。

示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)return 0;
        int sum = 0;
        dfs(root,sum);
        return sum;
    }
    void dfs(TreeNode* root,int &sum){
        if(root->left){
            if(!root->left->left && !root->left->right){
                sum+=root->left->val;
            }
            else{
                dfs(root->left,sum);
            }
        }
        if(root->right){
            dfs(root->right,sum);
        }
    }
}; 