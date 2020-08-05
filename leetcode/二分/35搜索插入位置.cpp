给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(!nums.size() || target>nums[nums.size()-1])return nums.size();
        int n = nums.size();
        int l = 0,r = n-1;
        while(l<r){
            int mid = (l+r)/2;
            if(nums[mid]>=target)r = mid;
            else l = mid+1;
        }
        return r;
    }
};