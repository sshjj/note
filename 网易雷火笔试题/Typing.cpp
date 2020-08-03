#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n ;
    cin>>n;
    vector<int>dp(n+1,0);
    dp[0] = 0;
    dp[1] = 1;
    for(int i =1;i<=n;i++){
        int j = i/2;
        if(i%2==0){
            dp[i] = min(dp[i-1]+1,dp[j]+7);
        }
        else{
            dp[i] = min(dp[i-1]+1,dp[j]+8);
        }
    }
    cout<<dp[n];
    system("pause");
    return 0;
}