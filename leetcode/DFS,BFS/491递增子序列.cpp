给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。

示例:

输入: [4, 6, 7, 7]
输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]


class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>path;
        dfs(nums,path,0);
        return res;
    }
    void dfs(vector<int>&nums,vector<int>path,int i){
        if(path.size()>=2)
            res.push_back(path);
        unordered_set<int>st;
        for(int j = i;j<nums.size();j++){
            if(path.size() && path.back()>nums[j])continue;
            if(st.find(nums[j])!=st.end())continue;
            st.insert(nums[j]);
            path.push_back(nums[j]);
            dfs(nums,path,j+1);
            path.pop_back();
        }
    }
};


//////////////////////////////////
class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>path;
        dfs(nums,path,0);
        return res;
    }
    void dfs(vector<int>&nums,vector<int>path,int i){
        if(i>=nums.size()){
            if(path.size()>=2)
                res.push_back(path);
            return;
        }
        if(path.empty() || nums[i]>=path.back()){
            path.push_back(nums[i]);
            dfs(nums,path,i+1);
            path.pop_back();
        }
        if(i>0 && !path.empty() && nums[i] == path.back())return ;
        dfs(nums,path,i+1);
    }
};