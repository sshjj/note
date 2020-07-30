在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

示例 1:

输入: [7,5,6,4]
输出: 5
// 归并排序
class Solution {
public:
    int merge(vector<int> &nums,int l,int r){
        if(l>=r)return 0;
        int mid = (l+ r) >>1;
        int res = merge(nums,l,mid)+merge(nums,mid+1,r);
        int i =l,j = mid+1;
        vector<int>temp;
        while(i<=mid && j<=r)
            if(nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else {
                temp.push_back(nums[j++]);
                res += mid -i+1;
            }
        while(i<=mid)temp.push_back(nums[i++]);
        while(j<r)temp.push_back(nums[j++]);
        i =l;
        for(auto x :temp)nums[i++] = x;
        return res;
    }
    int reversePairs(vector<int>& nums) {
        return merge(nums,0,nums.size()-1);
    }
};