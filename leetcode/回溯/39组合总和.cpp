#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int>& candidates,int target,int start){
        if(target == 0){
            res.push_back(path);
            return ;
        }
        for(int i = start;i<candidates.size() && target-candidates[i]>=0;i++){
            path.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0);
        return res;
    }
};
int main(){
    vector<int> c = {2,3,6,7};
    Solution ans;
    ans.combinationSum(c,7);
    system("pause");
    return 0;
}