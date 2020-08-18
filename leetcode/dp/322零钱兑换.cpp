给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:

输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        dp[0] = 0;
        for(int i =1;i<=amount;i++){
            for(int j = 0;j<coins.size();j++){
                if(i-coins[j]>=0 && dp[i-coins[j]]!=-1){
                    if(dp[i] == -1 || dp[i]>dp[i-coins[j]]+1){
                        dp[i] = dp[i-coins[j]]+1;
                    }
                }
            }
        }
        return dp[amount];
    }
};

//dfs+贪心+回溯
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int res = INT_MAX;
        if(!amount)return 0;
        sort(coins.rbegin(),coins.rend());
        dfs(coins,amount,0,0,res);
        return res == INT_MAX?-1:res;
    }
    void dfs(vector<int>& coins,int amount,int cnt,int index,int &res){
        if(amount == 0){res= min(res,cnt);return ;}
        if(index == coins.size())return ;
        for(int k = amount/coins[index];k>=0&& k+cnt<res;--k){
            dfs(coins,amount-k*coins[index],cnt+k,index+1,res);
        }
    }
};