请考虑一颗二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。



举个例子，如上图所示，给定一颗叶值序列为 (6, 7, 4, 9, 8) 的树。

如果有两颗二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。

如果给定的两个头结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>nums1,nums2;
        dfs(root1,nums1);
        dfs(root2,nums2);
        return nums1 == nums2;
        
    }
    void dfs(TreeNode* root,vector<int>&nums){
        if(!root)return;
        if(!root->left && !root->right){
            nums.push_back(root->val);
            return ;
        }
        dfs(root->left,nums);
        dfs(root->right,nums);
    }
};