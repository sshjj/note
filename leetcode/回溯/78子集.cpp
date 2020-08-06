class Solution {
public:
    int n;
    vector<vector<int>>res;
    void dfs(int first,vector<int>&nums,int num,vector<int>& path){
        if(path.size() == num){
            res.push_back(path);
        }
        for(int i =first;i<n;i++ ){
            path.push_back(nums[i]);
            dfs(i+1,nums,num,path);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        for(int i = 0;i<=n;i++){
            vector<int>path;
            dfs(0,nums,i,path);
        }
        return res;
    }
};