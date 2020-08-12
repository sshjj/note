给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
 

示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(),m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        dp[0][0] = 0;
        for(int i = 1;i<=n;i++)dp[i][0] = i;
        for(int i = 1;i<=m;i++)dp[0][i] = i;
        for(int i =1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                dp[i][j] = min(dp[i-1][j]+1,dp[i][j-1]+1);
                dp[i][j] = min(dp[i][j],dp[i-1][j-1]+ (word1[i-1]!=word2[j-1]));
            }
        }
        return dp[n][m];
    }
};