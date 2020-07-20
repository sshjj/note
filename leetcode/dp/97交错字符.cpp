/*
给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。

示例 1:

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出: true
示例 2:

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出: false
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(),m = s2.length(),k = s3.length();
        if(n+m!=k){
            return false;
        }
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        for(int i =0;i<n+1;i++){
            for(int j = 0;j<m+1;j++){
                if(i==0 && j==0) continue;
                if((i-1>=0 && dp[i-1][j] && s1[i-1]==s3[i+j-1])||(j-1>=0 && dp[i][j-1]&& s2[j-1]==s3[i+j-1])){
                    dp[i][j] = true;
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
        
    }
};

//滚动数组优化
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(),m = s2.size(),k = s3.size();
        if(m+n!=k){
            return false;
        }
        vector<int >dp(m+1,false);
        dp[0] = true;
        for(int i =0;i<n+1;i++){
            for(int j = 0;j<m+1;j++){
                int p = i+j-1;
                if(i>0){
                    dp[j] &= (s1[i-1]==s3[p]); 
                }
                if(j>0){
                    dp[j] |= (dp[j-1]&&s2[j-1]==s3[p]);
                }
            }
        }
        return dp[m];
    }
};