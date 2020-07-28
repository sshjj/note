从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。


例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root)return res;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            vector<int >path;
            int r = q.size();
            for(int i = 0;i<r;i++){
                auto t = q.front();
                path.push_back(t->val);
                q.pop();
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            res.push_back(path);
        }
        return res;
    }
};