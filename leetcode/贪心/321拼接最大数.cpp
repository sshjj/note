给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字。现在从这两个数组中选出 k (k <= m + n) 个数字拼接成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。

求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。

说明: 请尽可能地优化你算法的时间和空间复杂度。

示例 1:

输入:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
输出:
[9, 8, 6, 5, 3]

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(),n2 = nums2.size();
        vector<int>res;
        for(int i = max(0,k-n2);i<=min(k,n1);++i){
            res = max(res,mergeVector(maxVector(nums1,i),maxVector(nums2,k-i)));
        }
        return res;
    }
    vector<int>maxVector(vector<int>&nums,int k){
        int drop = nums.size() -k;
        vector<int> res;
        for(auto x:nums){
            while(drop>0 && !res.empty() && res.back()<x){
                res.pop_back();
                --drop;
            }
            res.push_back(x);
        }
        res.resize(k);
        return res;
    }
    vector<int>mergeVector(vector<int> nums1,vector<int>nums2){
        vector<int>res;
        while(!nums1.empty() || !nums2.empty()){
            vector<int>&tmp = (nums1>nums2)?nums1:nums2;
            res.push_back(tmp[0]);
            tmp.erase(tmp.begin());
        }
        return res;
    }
};