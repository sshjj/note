假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0,r = n-1;
        while(l<=r){
            while(l!=r && nums[l] == nums[r])r--;
            int mid = (l+r)/2;
            if(nums[mid] == target){
                return true;
            }
            else if(nums[mid]>target){
                if(nums[mid]>nums[r] && target<nums[l]){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            else{
                if(nums[mid]<nums[l]&&target>nums[r]){
                    r =mid-1;
                }
                else{
                    l = mid+1;
                }
            }
        }
        return false;
    }
};