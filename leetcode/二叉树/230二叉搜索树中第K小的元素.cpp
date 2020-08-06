给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 1

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cnt;
    int res;
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return res;
    }
    void dfs(TreeNode* root,int k){
        if(!root)return ;
        dfs(root->left,k);
        cnt++;
        if(cnt == k)res = root->val;
        dfs(root->right,k);
    }
};

/////////////迭代

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>st;
        int n = 0;
        TreeNode* cur = root;
        while(!st.empty()|| cur){
            while(cur){
                st.push(cur);
                cur = cur->left;
            }
            cur  = st.top();
            st.pop();
            n++;
            if(n == k)return cur->val;
            cur = cur->right;
        }
        return 0;
    }
};