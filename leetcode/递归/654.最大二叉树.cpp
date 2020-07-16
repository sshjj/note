/*
给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：

二叉树的根是数组中的最大元素。
左子树是通过数组中最大值左边部分构造出的最大二叉树。
右子树是通过数组中最大值右边部分构造出的最大二叉树。
通过给定的数组构建最大二叉树，并且输出这个树的根节点。

*/
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        return construct(nums,0,nums.size());
    }
    TreeNode* construct(vector<int>& nums,int l,int r){
        if(l == r)return nullptr;
        int maxi = maxn(nums,l,r);
        TreeNode* root = new TreeNode(nums[maxi]);
        root->left = construct(nums,l,maxi);
        root->right = construct(nums, maxi+1,r);
        return root;
    }
    int maxn(vector<int>& nums,int l,int r){
        int k = l;
        for(int i = l;i<r;i++){
            if(nums[k]<nums[i])
                k = i;
        }
        return k;
    }
};