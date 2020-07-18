/*
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]

返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
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
    vector<int> pre ,in;
    map<int,int>hash;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder,in = inorder;
        for(int i = 0;i<in.size();i++)hash[in[i]] = i;
        return dfs(0,pre.size()-1,0,in.size()-1);
    }
    TreeNode* dfs(int pl,int pr,int il ,int ir){
        if(pl>pr)return nullptr;
        auto root = new TreeNode(pre[pl]);
        int k = hash[root->val];
        TreeNode* left =  dfs(pl+1,pl+k-il,il,k-1);
        TreeNode* right = dfs(pl+k-il+1,pr,k+1,ir);
        root->left = left;
        root->right = right;
        return root;
    }
};