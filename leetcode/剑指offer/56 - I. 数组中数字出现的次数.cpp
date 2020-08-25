一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

示例 1：

输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int sum = 0;
        for(auto x:nums)sum^=x;
        int k = 0;
        while(!(sum>>k &1))k++;
        int first = 0;
        for(auto x:nums){
            if(x>>k&1)
                first^=x;
        }
        return vector<int>{first,first^sum};
    }
};