给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000 。

 

示例 1:
输入:

"bbbab"
输出:

4
一个可能的最长回文子序列为 "bbbb"。

示例 2:
输入:

"cbbd"
输出:

2
一个可能的最长回文子序列为 "bb"。

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i = n-1;i>=0;i--){
            dp[i][i] = 1;
            for(int j = i+1;j<n;j++){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1]+2;
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};