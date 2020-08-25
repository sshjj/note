给定一棵二叉搜索树，请找出其中第k大的节点。


示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 4

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
    vector<int>res;
    int kthLargest(TreeNode* root, int k) {
        dfs(root);
        reverse(res.begin(),res.end());
        return res[k-1];
    }
    void dfs(TreeNode* root){
        if(root == NULL)return;
        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
    }
};
