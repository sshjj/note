你有 k 个升序排列的整数数组。找到一个最小区间，使得 k 个列表中的每个列表至少有一个数包含在其中。

我们定义如果 b-a < d-c 或者在 b-a == d-c 时 a < c，则区间 [a,b] 比 [c,d] 小。

示例 1:

输入:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
输出: [20,24]
解释: 
列表 1：[4, 10, 15, 24, 26]，24 在区间 [20,24] 中。
列表 2：[0, 9, 12, 20]，20 在区间 [20,24] 中。
列表 3：[5, 18, 22, 30]，22 在区间 [20,24] 中。

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>>ordered;
        for(size_t k =0;k<nums.size();++k)
            for(auto n:nums[k])ordered.push_back({n,k});
        sort(ordered.begin(),ordered.end());
        int i = 0,k = 0;
        vector<int>ans;
        unordered_map<int,int>count;
        for(int j = 0;j<ordered.size();++j){
            if(!count[ordered[j].second]++)++k;
            if(k ==  nums.size()){
                while(count[ordered[i].second]>1)--count[ordered[i++].second];
                if(ans.empty() || ans[1] - ans[0] > ordered[j].first - ordered[i].first){
                    ans = vector<int>{ordered[i].first,ordered[j].first};
                }
            }
        }
        return ans;
    }
};