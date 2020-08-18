给定两个字符串s1, s2，找到使两个字符串相等所需删除字符的ASCII值的最小和。

示例 1:

输入: s1 = "sea", s2 = "eat"
输出: 231
解释: 在 "sea" 中删除 "s" 并将 "s" 的值(115)加入总和。
在 "eat" 中删除 "t" 并将 116 加入总和。
结束时，两个字符串相等，115 + 116 = 231 就是符合条件的最小和。
示例 2:

输入: s1 = "delete", s2 = "leet"
输出: 403
解释: 在 "delete" 中删除 "dee" 字符串变成 "let"，
将 100[d]+101[e]+101[e] 加入总和。在 "leet" 中删除 "e" 将 101[e] 加入总和。
结束时，两个字符串都等于 "let"，结果即为 100+101+101+101 = 403 。
如果改为将两个字符串转换为 "lee" 或 "eet"，我们会得到 433 或 417 的结果，比答案更大。

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(),m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = 1;i<=n;i++){
            dp[i][0] =dp[i-1][0]+ int(s1[i-1]);
        }
        for(int j = 1;j<=m;j++){
            dp[0][j] = dp[0][j-1]+ int(s2[j-1]);
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j]+ int(s1[i-1]),dp[i][j-1]+int(s2[j-1]));
                }
            }
        }
        return dp[n][m];
    }
};

/////
class Solution {
public:
    //题解：动态规划，转换为求1143. 最大公共字串的ASCII码之和
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(s1[i-1]==s2[j-1]){
                    //int+char，会发生类型转换，char会转换为10进制数字
                    dp[i][j]=dp[i-1][j-1]+s1[i-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int total=0;
        for(char c:s1)total+=c;
        for(char c:s2)total+=c;
        //最小ASCII删除和=两个字符串的ASCII码之和-最大公共字串的ASCII码之和
        return total-2*dp[m][n];
    }
};