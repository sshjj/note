给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。

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
    bool isBalanced(TreeNode* root) {
        if(root == NULL)return true;
        else
            return abs(dfs(root->left) - dfs(root->right))<=1 && isBalanced(root->left)&&isBalanced(root->right);
    }
    int dfs(TreeNode* root){
        if(root == NULL)return 0;
        else{
            return max(dfs(root->left),dfs(root->right))+1;
        }

    }
};

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
    bool isBalanced(TreeNode* root) {
        return dfs(root)>=0;
    }
    int dfs(TreeNode* root){
        if(root ==NULL)return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if(abs(l-r)>1||l ==-1 || r ==-1){
            return -1;
        }else{
            return max(l,r)+1;
        }
    }
};