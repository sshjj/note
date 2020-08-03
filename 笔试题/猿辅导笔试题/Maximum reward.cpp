#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;
const int MODN = 1e9+3;
vector<vector<int>>gra(MAXN);
vector<int>val(MAXN);
vector<int>dp(MAXN,-1);
int dfs(int u){
    if(dp[u] != -1)return dp[u];
    dp[u] = val[u];
    for(int i = 0;i<gra[u].size();i++){
        int nx = gra[u][i];
        int ret = dfs(nx);
        if(ret>0)dp[u] += ret;
    }
    return dp[u];
}
int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(b-2>=0 && b-2!=i)
            gra[b-2].emplace_back(i);
        val[i] = a;
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        ans = max(ans,dfs(i));
    }
    ans = (ans + MODN)%MODN;
    cout<< ans<<endl;
    system("pause");
    return 0;
}