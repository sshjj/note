给定一个二叉树，在树的最后一行找到最左边的值。

示例 1:

输入:

    2
   / \
  1   3

输出:
1

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
    int findBottomLeftValue(TreeNode* root) {
        if(!root)return -1;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* cur = nullptr;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(cur->right)q.push(cur->right);
            if(cur->left)q.push(cur->left);
        }
        return cur->val;
    }
};