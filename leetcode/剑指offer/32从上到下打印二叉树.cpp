从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回：

[3,9,20,15,7]

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
    vector<int> levelOrder(TreeNode* root) {
        vector<int>res;
        if(!root)return res;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            auto t = q.front();
            q.pop();
            res.push_back(t->val);
            if(t->left)q.push(t->left);
            if(t->right)q.push(t->right);
        }
        return res;

    }
};