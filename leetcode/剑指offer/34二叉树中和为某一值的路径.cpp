输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

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
    vector<int>path;
    vector<vector<int>>res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)return res;
        dfs(root,sum);
        return res;
    }
    void dfs(TreeNode* root,int sum){
        if(!root)return ;
        path.push_back(root->val);
        sum -=root->val;
        if(!root->left && !root->right &&!sum)res.push_back(path);
        dfs(root->left,sum);
        dfs(root->right,sum);
        path.pop_back();
    }
};