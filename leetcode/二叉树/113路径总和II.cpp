给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>res;
        vector<int>path;
        int path_val = 0;
        preorder(root,path_val,sum,path,res);
        return res;
    }
    void preorder(TreeNode* root,int &path_val,int sum,vector<int>&path,vector<vector<int>>&res){
        if(!root)return ;
        path_val += root->val;
        path.push_back(root->val);
        if(!root->left && !root->right && path_val == sum){
            res.push_back(path);
        }
        preorder(root->left,path_val,sum,path,res);
        preorder(root->right,path_val,sum,path,res);
        path_val -=root->val;
        path.pop_back();
    }
};