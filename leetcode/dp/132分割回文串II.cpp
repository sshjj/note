给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回符合要求的最少分割次数。

示例:

输入: "aab"
输出: 1
解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n);
        for(int i = 0;i<n;i++){
            dp[i] = i;
        }
        vector<vector<bool>>st(n,vector<bool>(n,false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<=i;j++){
                if(s[j] == s[i]&& (i-j<=2 || st[j+1][i-1])){
                    st[j][i] = true;
                }
            }
        }
        for(int i = 0;i<n;i++){
            if(st[0][i]){
                dp[i] = 0;
                continue;
            }
            for(int j = 0;j<i;j++){
                if(st[j+1][i]){
                    dp[i] = min(dp[i],dp[j]+1);
                }
            }
        }
        return dp[n-1];
    }
};

///////////////////////////////////////////
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>>isPar(n,vector<bool>(n,false));
        vector<int>dp(n+1,n);
        dp[0] = 0;
        for(int i =0;i<n;i++){
            for(int j = 0;j<=i;j++){
                if(s[j] == s[i]&&(i-j<3||isPar[j+1][i-1])){
                    isPar[j][i] = true;
                    dp[i+1]= min(dp[i+1],dp[j]+1);
                }
            }
        }
        return dp[n]-1;
    }
};