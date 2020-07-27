给定一个整数矩阵，找出最长递增路径的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。

示例 1:

输入: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
输出: 4 
解释: 最长递增路径为 [1, 2, 6, 9]。

```
class Solution {
public:
    vector<vector<int>>dp;
    vector<vector<int>>data;
    int n,m;
    int ans;
    int dx[4] ={-1,0,1,0},dy[4] = {0,1,0,-1};
    int f(int i,int j){
        if(dp[i][j])return dp[i][j];
        else{
            dp[i][j]=1;
            for(int k = 0;k<4;k++){
                int a = i+dx[k],b = j+dy[k];
                if(a<0||a>=n||b<0||b>=m)continue;
                if(data[a][b]>data[i][j])dp[i][j] = max(dp[i][j],f(a,b)+1);
            }
            return dp[i][j];
        }
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty())return 0;
        n = matrix.size();
        m = matrix[0].size();
        data = matrix;
        dp = vector<vector<int>>(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(dp[i][j] ==0)f(i,j);
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
```