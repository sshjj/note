给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

示例：

给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

class NumArray {
public:
    vector<int>prefix;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n+1,0);
        for(int i = 1;i<=n;i++){
            prefix[i] = prefix[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return prefix[j+1]-prefix[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */