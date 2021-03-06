输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

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
    bool res= true;
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return res;
    }
    int dfs(TreeNode* root){
        if(!root)return 0;
        int left = dfs(root->left),right = dfs(root->right);
        if(abs(left - right)>1)res = false;
        return max(left,right)+1;
    }
};