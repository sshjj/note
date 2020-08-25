给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。

 

示例：

输入：

   1
    \
     3
    /
   2

输出：
1

解释：
最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。


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
    int getMinimumDifference(TreeNode* root) {
        vector<int>nums;
        dfs(root,nums);
        int res = INT_MAX;
        for(int i =1;i<nums.size();i++){
            res = min(res,abs(nums[i]-nums[i-1]));
        }
        return res;

    }
    void dfs(TreeNode* root,vector<int>&nums){
        if(!root)return ;
        dfs(root->left,nums);
        nums.push_back(root->val);
        dfs(root->right,nums);
    }
};
