#include<bits/stdc++.h>
using namespace std;
int min_v;
void dfs(vector<int>&nums,int i,int suma,int sumb,int drop){
    if(i>=nums.size()){
        if(suma==sumb) min_v=min(min_v,drop);
        return;
    }
    dfs(nums,i+1,suma+nums[i],sumb,drop);
    dfs(nums,i+1,suma,sumb+nums[i],drop);
    dfs(nums,i+1,suma,sumb,drop+nums[i]);
}

int main()
{
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n,0);
        for(int i=0;i<n;i++) {cin>>nums[i];}
        min_v=INT_MAX;
        dfs(nums,0,0,0,0);
        cout<<min_v<<endl;
    }
    return 0;
}