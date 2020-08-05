给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

若这两个字符串没有公共子序列，则返回 0。

示例 1:

输入：text1 = "abcde", text2 = "ace" 
输出：3  
解释：最长公共子序列是 "ace"，它的长度为 3。

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = 1;i<=n;++i){
            for(int j = 1;j<=m;++j){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m = text2.size();
        int dp[n+1][m+1];
        for(int i = 0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int i = 0;i<=m;i++){
            dp[0][i] =0;
        }
        for(int i = 1;i<=n;++i){
            for(int j = 1;j<=m;++j){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};