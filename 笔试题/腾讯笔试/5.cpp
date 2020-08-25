#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
bool isok(string &s,int i,int j){
    int len=j-i+1;
    for(int k=i;k<i+len/2;k++)
        if(s[k]!=s[j+i-k]) return false;
    return true;
}

int main()
{
    string s;cin>>s;
    int m=s.size();
    vector<vector<int>>dp(m+1,vector<int>(m+1,inf));
    for(int i=0;i<m;i++) dp[i][i]=1;
    for(int i=0;i<m;i++)
        for(int j=i+1;j<m;j++){
            if(isok(s,i,j)) dp[i][j]=1;
            else{
                for(int k=i;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
            }
        }
    int n;cin>>n;
    while(n--){
        int a,b;cin>>a>>b;
        cout<<dp[a-1][b-1]<<endl;
    }
    system("pause");
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int s;
string str;
vector<vector<int>> dp;

bool judge(int l, int r)
{
    int edge = (r - l) / 2;
    for (int i = 0; i <= edge; ++i)
    {
        if (str[l + i] != str[r-i])
            return false;
    }
    return true;
}

int dfs(int l, int r)
{
    if (dp[l][r] != INT_MAX)
        return dp[l][r];
    if (judge(l, r))
        return dp[l][r] = 1;
    int mid;
    for (mid = l; mid < r; ++mid)
    {
        dp[l][r] = min(dp[l][r], dfs(l, mid) + dfs(mid + 1, r));
    }
    return dp[l][r];
}

int main()
{
    cin >> str;
    s = str.size();
    dp.assign(s, vector<int>(s, INT_MAX));
    int i;
    for (i = 0; i < s; ++i)
        dp[i][i] = 1;
    int n, l, r;
    cin >> n;
    while (n--)
    {
        cin >> l >> r;
        --l;
        --r;
        cout << dfs(l, r) << endl;
    }

    return 0;
}