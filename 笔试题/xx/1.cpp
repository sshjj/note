#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cost(n, vector<int>(m));
    vector<vector<int>> get(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> cost[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> get[i][j];
        }
    }
    vector<vector<int>>dp[n+1][m+1];
    dp[]
}
#include<bits/stdc++.h>
using namespace std;
const int MAXN=401;
vector<vector<pair<int,int>>> gra;
int n,m,dp[MAXN][MAXN][2];

int main()
{
    cin>>n>>m;
    gra.assign(n,vector<pair<int,int>>(m,{0,0}));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>gra[i][j].first;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>gra[i][j].second;
    dp[0][0][0]=gra[0][0].first;
    dp[0][0][1]=gra[0][0].second;
    for(int i=1;i<m;i++) dp[0][i][0]=gra[0][i].first+dp[0][i-1][0];
    for(int i=1;i<m;i++) dp[0][i][1]=gra[0][i].second+dp[0][i-1][1];
    for(int i=1;i<n;i++) dp[i][0][0]=gra[i][0].first+dp[i-1][0][0];
    for(int i=1;i<n;i++) dp[i][0][1]=gra[i][0].second+dp[i-1][0][1];
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++){
            dp[i][j][0]=gra[i][j].first;
            dp[i][j][1]=gra[i][j].second;
            if(dp[i-1][j][0]<dp[i][j-1][0]){
                dp[i][j][0]+=dp[i-1][j][0];
                dp[i][j][1]+=dp[i-1][j][1];
            }else if(dp[i-1][j][0]>dp[i][j-1][0]){
                dp[i][j][0]+=dp[i][j-1][0];
                dp[i][j][1]+=dp[i][j-1][1];
            }else{
                dp[i][j][0]+=dp[i][j-1][0];
                dp[i][j][1]+=max(dp[i-1][j][1],dp[i][j-1][1]);
            }
        }

    cout<<dp[n-1][m-1][0]<<" "<<dp[n-1][m-1][1]<<endl;
    return 0;
}