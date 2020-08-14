定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]

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
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
    void dfs(TreeNode* root){
        if(!root)return ;
        dfs(root->left);
        dfs(root->right);
        res.push_back(root->val);
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*>stk;
        stk.push(root);
        while(!stk.empty()){
            auto p = stk.top();
            stk.pop();
            if(p!=NULL)res.push_back(p->val);
            else continue;
            stk.push(p->left);
            stk.push(p->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

///// 模板实现
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*>st;
        if(root!=NULL)st.push(root);
        while(!st.empty()){
            auto node = st.top();
            if(node!=NULL){
                st.pop();
                st.push(node);
                st.push(NULL);
                if(node->right)st.push(node->right);
                if(node->left)st.push(node->left);
            }
            else{
                st.pop();
                node = st.top();
                st.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }
};