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

