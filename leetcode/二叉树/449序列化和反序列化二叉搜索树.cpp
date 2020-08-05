/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfs1(root,res);
        return res;
    }
    void dfs1(TreeNode* root,string &res){
        if(!root ){
            res += "#,";
            return ;
        }
        res += to_string(root->val)+ ',';
        dfs1(root->left,res);
        dfs1(root->right,res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int u =0;
        return dfs(data,u);
    }
    TreeNode* dfs(string &data,int& u){
        if(data[u] == '#'){
            u+=2;
            return NULL;
        }
        int t =0;
        bool is_minus = false;
        if(data[u] =='-'){
            is_minus =true;
            u++;
        }
        while(data[u]!=','){
            t= t*10+data[u]-'0';
            u++;
        }
        u++;
        TreeNode* root = new TreeNode(t);
        root->left = dfs(data,u);
        root->right = dfs(data,u);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));