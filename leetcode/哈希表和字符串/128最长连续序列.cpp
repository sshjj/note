给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<2)return nums.size();
        unordered_set<int>s(nums.begin(),nums.end());
        int res  =1;
        for(auto x:s){
            if(s.count(x-1)!=0)continue;
            int len = 1;
            while(s.count(x+1)!=0){
                len++;
                x++;
            }
            res = max(res,len);
        }
        return res;
    }
};