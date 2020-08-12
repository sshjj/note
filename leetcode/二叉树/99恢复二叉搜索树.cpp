二叉搜索树中的两个节点被错误地交换。

请在不改变其结构的情况下，恢复这棵树。

示例 1:

输入: [1,3,null,null,2]

   1
  /
 3
  \
   2

输出: [3,1,null,null,2]

   3
  /
 1
  \
   2

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
    void recoverTree(TreeNode* root) {
        vector<pair<int,TreeNode*>>inorder;
        if(root){
            dfs(root,inorder);
            int pi =-1,pj =-1;
            for(int i=0;i<inorder.size()-1;i++){
                if(inorder[i].first>inorder[i+1].first){
                    if(pi == -1){
                        pi = i;
                        pj = i+1;
                    }
                    else{
                        pj = i+1;
                        break;
                    }
                }
            }
            swap(inorder[pi].second->val,inorder[pj].second->val);
        }
    }
    void dfs(TreeNode* node,vector<pair<int,TreeNode*>>&inorder){
        if(!node)return ;
        dfs(node->left,inorder);
        inorder.push_back(make_pair(node->val,node));
        dfs(node->right,inorder);
    }
};

/////////////////////////////
//迭代
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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*>stk;
        TreeNode* x = nullptr;
        TreeNode* y = nullptr;
        TreeNode* pre = nullptr;
        while(!stk.empty()||root!=nullptr){
            while(root!=nullptr){
                stk.push(root);
                root=root->left;
            }
            root = stk.top();
            stk.pop();
            if(pre!=nullptr &&root->val<pre->val){
                y = root;
                if(x == nullptr){
                    x = pre;
                }
                else break;
            }
            pre = root;
            root = root->right;
        }
        swap(x->val,y->val);
    }
};


//morris 中序遍历
Morris 遍历算法整体步骤如下（假设当前遍历到的节点为 xx）：

1.如果 xx 无左孩子，则访问 x 的右孩子，即 x=x.right。
2.如果 xx 有左孩子，则找到 x 左子树上最右的节点（即左子树中序遍历的最后一个节点，xx 在中序遍历中的前驱节点），我们记为predecessor。根据 predecessor 的右孩子是否为空，进行如下操作。
    如果 predecessor 的右孩子为空，则将其右孩子指向 x，然后访问 x 的左孩子，即 x=x.left。
    如果 predecessor 的右孩子不为空，则此时其右孩子指向 xx，说明我们已经遍历完 xx 的左子树，我们将 predecessor 的右孩子置空，然后访问 x 的右孩子，即 x=x.right。
3.重复上述操作，直至访问完整棵树。
其实整个过程我们就多做一步：将当前节点左子树中最右边的节点指向它，这样在左子树遍历完成后我们通过这个指向走回了 xx，且能再通过这个知晓我们已经遍历完成了左子树，而不用再通过栈来维护，省去了栈的空间复杂度。

了解完这个算法以后，其他地方与方法二并无不同，我们同样也是维护一个 pred 变量去比较即可，具体实现可以看下面的代码，这里不再赘述。



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
    void recoverTree(TreeNode* root) {
        TreeNode* x = nullptr,*y = nullptr,*pre = nullptr,*predecessor = nullptr;
        while(root!=nullptr){
            if(root->left!=nullptr){
                predecessor = root->left;
                while(predecessor->right!=nullptr&&predecessor->right!=root){
                    predecessor = predecessor->right;
                }
                if(predecessor->right == nullptr){
                    predecessor->right = root;
                    root = root->left;
                }
                else{
                    if(pre!=nullptr && root->val<pre->val){
                        y = root;
                        if(x == nullptr){
                            x = pre;
                        }
                    }
                    pre = root;
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            else{
                if(pre!=nullptr && root->val<pre->val){
                    y =root;
                    if(x == nullptr){
                        x = pre;
                    }
                }
                pre = root;
                root = root->right;
            }
        }
        swap(x->val,y->val);
    }
};