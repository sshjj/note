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

class Solution {
public:
    int binary(vector<int>&nums,int target){
        int  l = 0,r = nums.size()-1, index = -1;
        while(index == -1){
            int mid = (l+r)/2;
            if(nums[mid] == target){
                index = mid;
            }
            else if(nums[mid]>target){
                if(mid == 0 || target>nums[mid-1])index = mid;
                r = mid-1;
            }
            else if(target>nums[mid]){
                if(mid == nums.size()-1 || target<nums[mid+1])index = mid+1;
                l = mid+1;
            }
        }
        return index;
    }
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        vector<int>stk;
        stk.push_back(nums[0]);
        for(int i = 1;i<nums.size();i++){
            if(nums[i]>stk.back()){
                stk.push_back(nums[i]);
            }
            else{
                int pos = binary(stk,nums[i]);
                stk[pos] = nums[i];
            }
        }
        return stk.size();
    }
};
