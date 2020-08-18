给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。

示例:

输入: [4, 6, 7, 7]
输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]

class Solution {
public:

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if(nums.empty())return {};
        set<vector<int>>res;
        vector<int>track;
        dfs(nums,res,track,0,nums.size());
        return vector<vector<int>>(res.begin(),res.end());
    }
    void dfs(vector<int>&nums,set<vector<int>>&res,vector<int>&track,int index,int n){
        if(track.size()>=2)res.insert(track);
        for(int i =index;i<n;i++){
            if(!track.empty() && track.back()>nums[i])continue;
            track.push_back(nums[i]);
            dfs(nums,res,track,i+1,n);
            track.pop_back();
        }
    }
};