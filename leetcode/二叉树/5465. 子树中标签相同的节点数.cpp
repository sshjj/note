/*
给你一棵树（即，一个连通的无环无向图），这棵树由编号从 0  到 n - 1 的 n 个节点组成，且恰好有 n - 1 条 edges 。树的根节点为节点 0 ，
树上的每一个节点都有一个标签，也就是字符串 labels 中的一个小写字符（编号为 i 的 节点的标签就是 labels[i] ）
边数组 edges 以 edges[i] = [ai, bi] 的形式给出，该格式表示节点 ai 和 bi 之间存在一条边。
返回一个大小为 n 的数组，其中 ans[i] 表示第 i 个节点的子树中与节点 i 标签相同的节点数。
树 T 中的子树是由 T 中的某个节点及其所有后代节点组成的树。

输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], labels = "abaedcd"
输出：[2,1,1,1,1,1,1]
解释：节点 0 的标签为 'a' ，以 'a' 为根节点的子树中，节点 2 的标签也是 'a' ，因此答案为 2 。注意树中的每个节点都是这棵子树的一部分。
节点 1 的标签为 'b' ，节点 1 的子树包含节点 1、4 和 5，但是节点 4、5 的标签与节点 1 不同，故而答案为 1（即，该节点本身）。
*/

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string s) {
        vector<vector<int>>g(n);
        for(int i = 0;i<n-1;++i){
            int u = edges[i][0],v = edges[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> res(n),cnt(30);
        dfs(0,-1,res,cnt,g,s);
        return res;
    }
    void dfs(int u,int p ,vector<int>&res,vector<int>&cnt,vector<vector<int>>&g,string &s){
        int cur = s[u]-'a';
        int backup = cnt[cur];
        ++cnt[cur];
        for(int i = 0;i<g[u].size();++i){
            int v = g[u][i];
            if(v!=p){
                dfs(v,u,res,cnt,g,s);
            }
        }
        res[u] = cnt[cur] - backup;
    }
};