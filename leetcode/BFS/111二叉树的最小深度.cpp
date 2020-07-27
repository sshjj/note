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
    int minDepth(TreeNode* root) {
        if(root == NULL)return 0;
        queue<TreeNode*>q ;
        q.push(root);
        int depth = 1;
        while(!q.empty()){
            int n = q.size();
            for(int i =0;i<n;i++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left  == NULL && cur->right == NULL)
                    return depth;
                if(cur->left != NULL)
                    q.push(cur->left);
                if(cur->right != NULL)
                    q.push(cur->right);
            }
            depth++;
        }
        return depth;
    }
};