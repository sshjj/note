给定一个未排序的整数数组，找到最长递增子序列的个数。

示例 1:

输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
示例 2:

输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.empty())return 0;
        int n = nums.size(),maxlen = 0;
        vector<int>dp(n,1),count(n,1);
        for(int i =0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(dp[j]+1>dp[i]){
                        dp[i] = dp[j]+1;
                        count[i] = count[j];
                    }
                    else if(dp[j]+1 == dp[i]){
                        count[i] +=count[j];
                    }
                }
            }
            maxlen = max(maxlen,dp[i]);
        }
        int res = 0;
        for(int i =0;i<n;i++){
            if(maxlen == dp[i]){
                res+=count[i];
            }
        }
        return res;
    }
};