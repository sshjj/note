给定一个二叉树，它的每个结点都存放着一个整数值。

找出路径和等于给定数值的路径总数。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

示例：

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有:

1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11

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
    int res=0;
    int pathSum(TreeNode* root, int sum) {
        if(!root)return 0;
        dfs(root,sum);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        return res;
    }
    void dfs(TreeNode* root,int sum){
        if(root == nullptr)return ;
        sum -= root->val;
        if(sum == 0){
            res++;
        }
        dfs(root->left,sum);
        dfs(root->right,sum);
    }
};
//前缀和
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
    int pathSum(TreeNode* root, int sum) {
        if(!root)return 0;
        unordered_map<int,int>prefix;
        prefix[0] = 1;
        int res = 0;
        dfs(root,sum,0,prefix,res);
        return res;
    }
    void dfs(TreeNode* root,int sum,int cur_sum,unordered_map<int,int>&prefix,int &res){
        if(!root)return ;
        cur_sum+=root->val;
        int prefix_to_find = cur_sum-sum;
        if(prefix.find(prefix_to_find)!=prefix.end()){
            res+=prefix[prefix_to_find];
        }
        ++prefix[cur_sum];
        dfs(root->left,sum,cur_sum,prefix,res);
        dfs(root->right,sum,cur_sum,prefix,res);
        --prefix[cur_sum];
    }
};