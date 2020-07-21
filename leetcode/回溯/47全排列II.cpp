class Solution {
public:
    vector<vector<int>>res;
    vector<bool>st;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>track;
        st = vector<bool>(nums.size(),false);
        sort(nums.begin(),nums.end());
        dfs(nums,track);
        return res;
    }
    void dfs(vector<int>& nums,vector<int>& track){
        if(track.size() == nums.size()){
            res.push_back(track);
            return;
        }
        for(int i = 0 ;i<nums.size();i++){
            if(st[i])continue;
            if(i>0 && nums[i]== nums[i-1] && st[i-1]==false)continue;
            track.push_back(nums[i]);
            st[i] = true;
            dfs(nums,track);
            track.pop_back();
            st[i] = false;
                
        }
    }
};