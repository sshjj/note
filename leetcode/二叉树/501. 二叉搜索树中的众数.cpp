给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：

结点左子树中所含结点的值小于等于当前结点的值
结点右子树中所含结点的值大于等于当前结点的值
左子树和右子树都是二叉搜索树
例如：
给定 BST [1,null,2,2],

   1
    \
     2
    /
   2
返回[2].

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
    vector<int> findMode(TreeNode* root) {
        if(!root)return {};
        TreeNode* pre = nullptr;
        vector<int>res;
        int maxTimes = 0,curTimes = 1;
        dfs(root,pre,curTimes,maxTimes,res);
        return res;

    }
    void dfs(TreeNode* &root,TreeNode* &pre,int &curTimes,int &maxTimes,vector<int>& res){
        if(!root)return ;
        dfs(root->left,pre,curTimes,maxTimes,res);
        if(pre){
            curTimes = (root->val == pre->val)?curTimes+1:1;
        }
        if(curTimes == maxTimes){
            res.push_back(root->val);
        }
        else if(curTimes>maxTimes){
            res.clear();
            res.push_back(root->val);
            maxTimes = curTimes;
        }
        pre = root;
        dfs(root->right,pre,curTimes,maxTimes,res);
    }
};