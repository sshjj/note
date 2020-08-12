还记得童话《卖火柴的小女孩》吗？现在，你知道小女孩有多少根火柴，请找出一种能使用所有火柴拼成一个正方形的方法。不能折断火柴，可以把火柴连接起来，并且每根火柴都要用到。

输入为小女孩拥有火柴的数目，每根火柴用其长度表示。输出即为是否能用所有的火柴拼成正方形。

示例 1:

输入: [1,1,2,2,2]
输出: true

解释: 能拼成一个边长为2的正方形，每边两根火柴。
示例 2:

输入: [3,3,3,3,4]
输出: false

解释: 不能用所有火柴拼成一个正方形。

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size()<4)return false;
        int sum = 0;
        for(auto x:nums)sum+=x;
        if(sum%4)return false;
        sort(nums.rbegin(),nums.rend());
        int bucket[4] = {0};
        return dfs(0,nums,sum/4,bucket);
    }
    bool dfs(int i,vector<int>&nums,int target,int bucket[]){
        if(i>=nums.size()){
            return bucket[0] == target &&bucket[1] == target &&bucket[2] == target &&bucket[3] == target;
        }
        for(int j = 0;j<4;j++){
            if(bucket[j]+nums[i]>target){
                continue;
            }
            bucket[j]+=nums[i];
            if(dfs(i+1,nums,target,bucket)){
                return true;
            }
            bucket[j] -=nums[i];
        }
        return false;
    }
};

//位运算
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size()<4)return false;
        int sum = 0;
        for(auto x:nums)sum+=x;
        if(sum%4)return false;
        int target = sum/4;
        vector<int>ok_subset;
        vector<int>ok_half;
        int all = 1<<nums.size();
        for(int i =0;i<all;i++){
            int sum = 0;
            for(int j =0;j<nums.size();j++){
                if(i&(1<<j)){
                    sum+=nums[j];
                }
            }
            if(sum == target){
                ok_subset.push_back(i);
            }
        }
        for(int i = 0;i<ok_subset.size();i++){
            for(int j =i+1;j<ok_subset.size();j++){
                if((ok_subset[i]&ok_subset[j])==0){
                    ok_half.push_back(ok_subset[i]|ok_subset[j]);
                }
            }
        }
        for(int i =0;i<ok_half.size();i++){
            for(int j = i+1;j<ok_half.size();j++){
                if((ok_half[i]&ok_half[j])==0){
                    return true;
                }
            }
        }
        return false;
    }
};