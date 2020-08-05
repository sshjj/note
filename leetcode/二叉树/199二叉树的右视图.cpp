给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//bfs
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        vector<int>res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int cnt = q.size();
            for(int i = 0;i<cnt;i++){
                auto node = q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                if(i == cnt-1)res.push_back(node->val);
            }
        }
        return res;
    }
};

//dfs
class Solution {
public:
    vector<int>res;
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
        return res;
    }
    void dfs(TreeNode* root,int depth){
        if(root == NULL)return ;
        if(res.size() == depth)res.push_back(root->val);
        dfs(root->right,depth+1);
        dfs(root->left,depth+1);
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        queue<pair<TreeNode*,int>>q;
        if(root){
            q.push(make_pair(root,0));
        }
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int depth = q.front().second;
            q.pop();
            if(view.size() == depth)
                view.push_back(node->val);
            else{
                view[depth] = node->val;
            }
            if(node->left){
                q.push(make_pair(node->left,depth+1));
            }
            if(node->right){
                q.push(make_pair(node->right,depth+1));
            }
        }
        return view;
    }
};