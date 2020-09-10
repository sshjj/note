给你一个大小为 m x n 的矩阵 mat 和一个整数阈值 threshold。

请你返回元素总和小于或等于阈值的正方形区域的最大边长；如果没有这样的正方形区域，则返回 0 。
 

示例 1：



输入：mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
输出：2
解释：总和小于 4 的正方形的最大边长为 2，如图所示。

class Solution {
public:
    int a[305][305];
    long long s[305][305];
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        memset(s,0,sizeof(s));
        for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){
                a[i][j] = mat[i-1][j-1];
                s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j =1;j<=m;j++){
                for(int k =1;k<=i&&k<=j;++k){
                    if(s[i][j]-s[i-k][j]-s[i][j-k]+s[i-k][j-k]<=threshold)
                        ans = max(ans,k);
                }
            }
        }
        return ans;
    }
};