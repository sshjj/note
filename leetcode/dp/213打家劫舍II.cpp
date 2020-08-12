你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [2,3,2]
输出: 3
解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。

class Solution {
public:
    int rob(vector<int>& nums) {
        if(!nums.size())return 0;
        if(nums.size() ==1)return nums[0];
        if(nums.size() ==2)return max(nums[1],nums[0]);
        int n = nums.size();
        vector<int>dp(n,0),dp1(n,0);
        dp[0] = 0,dp[1] = nums[1],dp[2] = max(nums[1],nums[2]);
        dp1[0] = nums[0],dp1[1] =max(nums[0],nums[1]);
        int res = 0;
        for(int i = 2;i<n;i++){
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
            dp1[i] = max(dp1[i-2]+nums[i],dp1[i-1]);
            res = max(dp[n-1],dp1[n-2]);
        }
        return res;
    }
};