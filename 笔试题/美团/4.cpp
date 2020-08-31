#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4+10;
vector<vector<int>> gra(MAXN);
vector<int> distx;
vector<int> disty;
vector<int> flag;
void dfs(int u,int sta){
    flag[u] = 1;
    for(int i=0;i<(int)gra[u].size();i++){
        int nx=gra[u][i];
        if(flag[nx])continue;
        if(sta == 0)distx[nx] = distx[u] + 1;
        else disty[nx] = disty[u] + 1;
        dfs(nx,sta);
    }
    
}
void solve(){
    int n;cin>>n;
    int x,y;cin>>x>>y;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        gra[a].emplace_back(b);
        gra[b].emplace_back(a);
    }
    distx.assign(n+1,0);
    flag.assign(n+1,0);
    dfs(x,0);
    disty.assign(n+1,0);
    flag.assign(n+1,0);
    dfs(y,1);
    int ans = -1e9;
    for(int i=1;i<=n;i++){
        
        if(disty[i]<distx[i])
        ans = max(ans,max(distx[i],disty[i]));
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
	return 0;
}