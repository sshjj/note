#include<bits/stdc++.h>
using namespace std;
int main(){
    int v1;
    vector<int> nums;
    cin >> v1;
    nums.push_back(v1);
    while(cin.get() != '\n')
    {
        cin >> v1;
        nums.push_back(v1);
    }
    vector<int> dp={0,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN};
    for(auto a:nums){
        vector<int>dpNext={0,0,0,0,0,0,0};
        int mod=a%7;
        for(int i=0;i<7;++i){
            dpNext[i]=max(dp[i],dp[(7+i-mod)%7]+a);
        }
        dp=dpNext;
    }
    cout<< dp[0]<<endl;
    return 0;
}