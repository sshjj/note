#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<vector<int>>> dp;
vector<int> arrmv;
const int MAXN = 100;
int dfs(int l,int r,int level){
    if(l>r)return 0;
    if(l == r)return arrmv[l]*level;
    if(dp[l][r][level]!=-1)return dp[l][r][level];
    dp[l][r][level] = 1e9;
    for(int i=l;i<=r;i++){
        dp[l][r][level] = min(dp[l][r][level],arrmv[i]*level+dfs(l,i-1,level+1)+dfs(i+1,r,level+1));
    }
    return dp[l][r][level];
}
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        arrmv.push_back(t);
    }
    dp.assign(MAXN,vector<vector<int>> (MAXN,vector<int>(MAXN,-1)));
    
    cout<<dfs(0,n-1,0)<<endl;;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
	return 0;
}