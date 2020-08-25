给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

说明:
不允许旋转信封。

示例:

输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出: 3 
解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。

本题属于300. 最长上升子序列的子题，难点在于如何处理envelopes数组？解决方法当然是排序了，然而这个排序还是比较难想的，我讲一下把。
排序：排序的主要作用是降维，将二维数组转换为一维数组，然后进行寻找最长上升子序列。
1）若w不相同，则按w由小到大进行排序。这样做的好处是：由于w由小到大进行排序了，那么只有h是上升的才能构成上升的子序列（即w已经可套娃了，判断h是否可套娃即可）。
比如[1,1]、[2,0]、[3,1]、[4,2]，降维之后的数组为[1,0,1,2]，这里可套娃的子序列有[1,1]、[4,2]对应[1,2]，还有[2,0]、[3,1]、[4,2]对应[0,1,2]等。
2）若w相同，则按h由大到小排序进行排序。这样做的好处是：由于w相等，那么只有h由大到小排序才不会计算重复的子序列（即w相等，只有h由大到小排序才不会重复计算套娃信封）。
比如[3,4]、[4,6]、[4,7]，若按h由小到大排序降维之后的数组为[4,6,7]，这样形成的可套娃的信封长度为3，这个是不正确的，因为只有(w2>w1,h2>h1)才能进行套娃。若我们按h由大到小排序之后降维之后的数组为[4,7,6]，这样可形成两个长度为2的可套娃子序列[3,4]、[4,7]和[3,4]、[4,6]，这样便满足条件了。

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty())return 0;
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>&a,const vector<int>&b){
            return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);
        });
        int n =envelopes.size(),res = 0;
        vector<int>dp(n,1);
        for(int i =0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(envelopes[j][1]<envelopes[i][1]){
                    dp[i] = max(dp[j]+1,dp[i]);
                }
            }
            res = max(dp[i],res);
        }
        return res;
    }
};

//优化：动态规划+二分法，时间复杂度O(nlogn)，空间复杂度O(n)
    int maxEnvelopes(vector<vector<int>>& envelopes){
        if(envelopes.empty())return 0;
        sort(envelopes.begin(),envelopes.end(),[](const auto& a,const auto& b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);
        });
        vector<int> dp;
        for(auto& en:envelopes){
            int idx=lower_bound(dp.begin(),dp.end(),en[1])-dp.begin();
            if(idx>=dp.size()){
                dp.emplace_back(en[1]);
            }
            else{
                dp[idx]=en[1];
            }
        }
        return dp.size();
    }
};