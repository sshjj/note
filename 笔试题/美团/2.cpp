#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n,0);
    for(int i =0;i<n;i++){
        vector<int>nums(n,0);
        int flag = 1;
        for(int j =0;j<n;j++){
            cin>>nums[i];
            if(flag && !v[nums[i]]){
                cout<<nums[i]<<' ';
                v[nums[i]] = 1;
                flag = 0;
            }
        }
    }
    return 0;
}