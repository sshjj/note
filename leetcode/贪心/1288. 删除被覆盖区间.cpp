给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。

只有当 c <= a 且 b <= d 时，我们才认为区间 [a,b) 被区间 [c,d) 覆盖。

在完成所有删除操作后，请你返回列表中剩余区间的数目。

 

示例：

输入：intervals = [[1,4],[3,6],[2,8]]
输出：2
解释：区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty())return {};
        //注意要先排序
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int ans = n;
        for(int i=0;i<n;++i){
            for(int j =0;j<n;j++){
                if(i!=j && intervals[i][0]>=intervals[j][0]&&intervals[i][1]<=intervals[j][1])                 {
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};