给出 n 个数对。 在每一个数对中，第一个数字总是比第二个数字小。

现在，我们定义一种跟随关系，当且仅当 b < c 时，数对(c, d) 才可以跟在 (a, b) 后面。我们用这种形式来构造一个数对链。

给定一个对数集合，找出能够形成的最长数对链的长度。你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。

示例 :

输入: [[1,2], [2,3], [3,4]]
输出: 2
解释: 最长的数对链是 [1,2] -> [3,4]
注意：

给出数对的个数在 [1, 1000] 范围内。

///dp ，类似300最长上升子序列  ， 同样适用   354俄罗斯套娃信封问题
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.empty())return 0;
        sort(pairs.begin(),pairs.end(),[](const vector<int>&a,const vector<int>&b){
            return (a[0] == b[0] && a[1]<b[1])||(a[0]<b[0]);
        });
        int n = pairs.size(),res = 0;
        vector<int>dp(n,1);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};


///区间贪心法，转换为435. 计算无重叠子区间数   435无重复区间 
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.empty())return 0;
        sort(pairs.begin(),pairs.end(),[](const vector<int>&a,const vector<int>&b){
            return (a[1]<b[1]) || (a[1] == b[1] && a[0]<b[0]);
        });
        int count = 1,end = pairs[0][1];
        for(const auto& p: pairs){
            if(p[0]>end){
                count++;
                end = p[1];
            }
        }
        return count;
    }
};