/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* 递归
    1.找终止条件
    2.找返回值
    3.本级递归应该做什么
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int res = 0;
        if(root == nullptr)
            return 0;
        int l  = maxDepth(root->left);
        int r = maxDepth(root->right);
        res = max(l,r)+1;
        return res;
        
    }
};