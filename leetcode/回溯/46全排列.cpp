给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
递归+回溯  改进用swap

class Solution {
public:
    vector<vector<int>> res;
    vector<bool>st;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>track;
        st = vector<bool>(nums.size(),false);
        dfs(nums,track);
        return res;
    }
    void dfs(vector<int>& nums,vector<int>& track){
        if(track.size() == nums.size()){
            res.push_back(track);
            return;
        }
        for(int i = 0 ;i<nums.size();++i){
            if(!st[i])
            {
                st[i] = true;
                track.push_back(nums[i]);
                dfs(nums,track);
                track.pop_back();
                st[i] = false;
            }
        }
    }
};