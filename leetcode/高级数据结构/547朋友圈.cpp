班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。所谓的朋友圈，是指所有朋友的集合。

给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。

示例 1:

输入: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
输出: 2 
说明：已知学生0和学生1互为朋友，他们在一个朋友圈。
第2个学生自己在一个朋友圈。所以返回2。

//////////////////////////////////////////////////////
//dfs方法
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<int>v(M.size(),0);
        int cnt=0;
        for(int i =0;i<M.size();i++){
            if(v[i] == 0 ){
                dfs(i,M,v);
                cnt++;
            }
        }
        return cnt;
    }
    void dfs(int u,vector<vector<int>>&M,vector<int>&v){
        v[u] = 1;
        for(int i =0;i<M[u].size();i++){
            if(v[i] == 0 && M[u][i] == 1){
                dfs(i,M,v);
            }
        }
    }
};

////////////////////////////////////////////////////////////////////
//并查集
class Solution {
public:
    int find(vector<int>&Vec,int n){
        if(Vec[n] == -1)
            return n;
        return find(Vec,Vec[n]);
    }
    void Union(vector<int>&Vec,int m,int n){
        int m1 = find(Vec,m);
        int n1 = find(Vec,n);
        if(m1!=n1){
            Vec[m1] = n1;
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n  = M.size();
        vector<int>parent(n,-1);
        for(int i =0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(M[i][j] == 1 && i!=j){
                    Union(parent,i,j);
                }
            }
        }
        int count =0;
        for(int i =0;i<n;i++){
            if(parent[i] == -1){
                count++;
            }
        }
        return count;
    }
};