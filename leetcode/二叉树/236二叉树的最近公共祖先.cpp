给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]



示例 1:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root==q)return root;
        auto left = lowestCommonAncestor(root->left,p,q);
        auto right = lowestCommonAncestor(root->right,p,q);
        if(!left)return right;
        if(!right)return left;
        return root;
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path;
        vector<TreeNode*>p_path;
        vector<TreeNode*>q_path;
        int finish = 0;
        preorder(root,p,path,p_path,finish);
        path.clear();
        finish = 0;
        preorder(root,q,path,q_path,finish);
        int path_len = 0;
        if(p_path.size()<q_path.size()){
            path_len = p_path.size();
        }
        else{
            path_len = q_path.size();
        }
        TreeNode *res = 0;
        for(int i = 0;i<path_len;i++){
            if(p_path[i]==q_path[i])
                res = p_path[i];
        }
        return res;
    }
    void preorder(TreeNode* node,TreeNode* search,vector<TreeNode*>&path,vector<TreeNode*>&res,int finish){
        if(!node || finish)
            return;
        path.push_back(node);
        if(node == search){
            finish = 1;
            res = path;
        }
        preorder(node->left,search,path,res,finish);
        preorder(node->right,search,path,res,finish);
        path.pop_back();
    }
};