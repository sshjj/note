class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int>hash;
        for(int i = 0;i<nums.size();i++){
            if(hash.count(nums[i])==1)
                return nums[i];
            else
                hash.insert(nums[i]);
        }
        return 0;
    }
};