数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

示例：

输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0)return {};
        vector<string> res;
        dfs(res,"",n,0,0);
        return res;
    }
    void dfs(vector<string>&res,string path,int n,int l,int r){
        if(l<r || l>n || r>n)return ;
        if(l == n&& r ==n){
            res.push_back(path);
            return ;
        }
        dfs(res,path+"(",n,l+1,r);
        dfs(res,path+")",n,l,r+1);

    }
};