//k = 1
//只买进卖出一次
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())return 0;
        int n = prices.size();
        int dp_i_0 = 0,dp_i_1 = INT_MIN;

        for(int i =0;i<n;i++){
            dp_i_0 = max(dp_i_0,dp_i_1+prices[i]);
            dp_i_1 = max(dp_i_1,-prices[i]);
        }
        return dp_i_0;
    }
};