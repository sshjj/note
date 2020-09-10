给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

 

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>record;
        for(const auto& it:nums){
            record[it]++;
        }
        vector<pair<int,int>>temp;
        for(const auto& it:record){
            temp.push_back(it);
        }
        sort(temp.begin(),temp.end(),[=](pair<int,int>&a,pair<int,int>&b){return a.second >b.second;});
        vector<int>res;
        auto it = temp.cbegin();
        for(int i =0;i<k;i++){
            res.push_back(it->first);
            it++;
        }
        return res;
    }
};