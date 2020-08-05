给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，
每步可以删除任意一个字符串中的一个字符。

示例：

输入: "sea", "eat"
输出: 2
解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
//最长公共子序列， dp[i][j]表示s1的前i个和s2前j个字符的最长公共子序列长度
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        dp[0][0] = 0;
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return m+n-2*dp[m][n];
    }
};
//直接dp dp[i][j]表示s1前i个和s2前j个相等时最小的删除数
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int dp[m+1][n+1];
        for(int i = 0;i<=m;i++){
            for(int j = 0;j<=n;j++){
                if(i == 0||j == 0){
                    dp[i][j] = i+j;
                }
                else{
                    if(word1[i-1] == word2[j-1]){
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = 1+min(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        return dp[m][n];
    }
};

//一维dp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int>dp(m+1);
        for(int i = 0;i<=m;i++){
            vector<int>temp(n+1);
            for(int j = 0;j<=n;j++){
                if(i == 0||j == 0){
                    temp[j] = i+j;
                }
                else{
                    if(word1[i-1] == word2[j-1]){
                        temp[j] = dp[j-1];
                    }
                    else{
                        temp[j] = 1+min(dp[j],temp[j-1]);
                    }
                }
            }
            dp = temp;
        }
        return dp[n];
    }
};