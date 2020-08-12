#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int>a(n,0);
        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        vector<int>b(n-1,0);
        for(int i = 0;i<n-1;i++){
            cin>>b[i];
        }
        vector<int>dp(n,0);
        dp[0] = a[0];
        dp[1] = min(a[0]+a[1],b[0]);
        if(n>1){
            for(int i = 2;i<n;i++){
                dp[i] = min(dp[i-1]+a[i],dp[i-2]+b[i-1]);
            }
        }
        int res = dp[n-1];
        int hour = res/3600;
        int min = (res%3600)/60;
        int sec = (res%3600)%60;
        int hours = hour+8;
        if(hour>4){
            printf("%02d:%02d:%02d pm",hours,min,sec);
        }
        else{
            printf("%02d:%02d:%02d am",hours,min,sec);
        }
    }
    return 0;
}