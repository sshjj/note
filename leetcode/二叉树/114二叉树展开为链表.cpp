给定一个二叉树，原地将它展开为一个单链表。

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

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
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while(cur!=nullptr){
            if(cur->left!=nullptr){
                auto nex = cur->left;
                auto pre = nex;
                while(pre->right!=nullptr){
                    pre = pre->right;
                }
                pre->right = cur->right;
                cur->left = nullptr;
                cur->right = nex;
            }
            cur = cur->right;
        }
    }
};
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
    void flatten(TreeNode* root) {
        vector<TreeNode*>val;
        dfs(root,val);
        for(int i = 1;i<val.size();i++){
            val[i-1]->left = NULL;
            val[i-1]->right  = val[i];
        }
    }
    void dfs(TreeNode* node,vector<TreeNode*>& val){
        if(!node)return;
        val.push_back(node);
        dfs(node->left,val);
        dfs(node->right,val);
    }
};

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
    void flatten(TreeNode* root) {
        TreeNode* last = NULL;
        dfs(root,last);
    }
    void dfs(TreeNode* node,TreeNode* &last){
        if(!node)return ;
        if(!node->left && !node->right){
            last = node;
            return;
        }
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        TreeNode* left_last = NULL;
        TreeNode* right_last = NULL;
        if(left){
            dfs(left,left_last);
            node->left = NULL;
            node->right = left;
            last = left_last;
        }
        if(right){
            dfs(right,right_last);
            if(left_last){
                left_last->right = right;
            }
            last = right_last;
        }
    }
};