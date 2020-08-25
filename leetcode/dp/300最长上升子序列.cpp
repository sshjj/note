给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?


题解：

思路1：动态规划，时间复杂度O(n2)，空间复杂度为O(n)。
状态：dp[i]表示以nums[i]结尾的最长上升子序列的长度
状态转移方程：dp[i]=max(dp[i],dp[j]+1)。设j∈[0,i)，考虑每轮计算新dp[i]时，遍历[0,i)列表区间。若nums[j]<nums[i]，那么dp[i]=max(dp[i],dp[j]+1)；否则dp[i]不变。
思路2：动态规划+二分查找，时间复杂度O(nlogn)，空间复杂度O(n)。
思路2是思路1的优化，计算每个dp值需要O(n)的时间复杂度，二分查找num需要O(logn)的时间复杂度。
遍历nums，我们需要找到大于等于num的最小值的位置idx。若idx大于等于dp数组的大小，则表示我们需要将num添加到dp后面，这样可维持上升子序列的增长；若idx小于dp数组的大小，则表示我们需要更新dp[idx]的值，这样可保证上升子序列中每个值相对较小。
//dp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> dp(n,0);
        for(int i = 0;i<n;i++){
            dp[i] = 1;
            for(int j = 0;j<i;j++){
                if(nums[i]>nums[j])
                    dp[i] = max(dp[i],dp[j]+1);
            }
        }
        for(int i = 0;i<n;i++)res = max(res,dp[i]);
        return res;
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        vector<int>dp(nums.size(),0);
        dp[0] = 1;
        int res = 1;
        for(int i =1;i<nums.size();i++){
            dp[i] = 1;
            for(int j =0;j<i;j++){
                if(nums[i]>nums[j]&& dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                }
            }
            if(res<dp[i]){
                res = dp[i];
            }
        }
        return res;
    }
};

//二分
class Solution {
public:
    int binarySearch(int low,int high,vector<int>&memo,int target){
        while(low<high){
            int mid = (low+high)/2;
            if(target>memo[mid]){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        memo[low] = target;
        return low;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n  = nums.size();
        if(n<=1){
            return n;
        }
        vector<int>memo(n,0);
        int res = 0;
        for(int i = 0;i<n;i++){
            if(binarySearch(0,res,memo,nums[i]) == res){
                res++;
            }
        }
        return res;
    }
};

    //题解2：动态规划+二分查找
    int lengthOfLIS(vector<int>& nums){
        /*vector<int> dp(nums.size(),0);
        //res为最长上升子序列的长度
        int res=0;
        for(int &num:nums){
            //二分法：找到大于等于num的最小值dp[left]
            int left=0,right=res;
            while(left<right){
                int mid=left+((right-left)>>1);
                if(dp[mid]>=num)right=mid;
                else left=mid+1;
            }
            //更新dp[left]为nums，这样可保证left位置的值在当前上升子序列中最小
            dp[left]=num;
            //若res和left相等，即num大于res中的最大元素，所以num需要添加在res的后面，此时res需要+1
            if(res==left)res++;
        }
        return res;*/
        //换一种写法，与上面思路代码更接近
        if(nums.size()<2)return nums.size();
        vector<int> dp;
        for(int &num:nums){
            //二分法寻找大于等于num的最小值的位置，若该位置大于等于size，那么我们需要将num添加在dp尾部；否则更新idx的值，保证idx的值是最小的
            auto idx=lower_bound(dp.begin(),dp.end(),num)-dp.begin();
            if(idx>=dp.size())dp.emplace_back(num);
            else dp[idx]=num;
        }
        return dp.size();
    }
};