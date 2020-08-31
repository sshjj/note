#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    vector<int>nums(n,0);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    int res  =0;
    vector<int>tmp;
    for(int i =1;i<=m;i++){
        for(int j = m;j>=i;j--){
            bool flag = true;
            int tmp = 0;
            for(int k = 0;k<nums.size();k++){
                if(nums[k]>0 && nums[k]<i || nums[k]>j && nums[k]<m+1){
                   if(nums[k]>=tmp){
                       tmp = nums[k];
                       continue;
                   }
                   else{
                       flag = false;
                       break;
                   }
                }
            }
            if(flag)res++;
            else break;
        }
    }
    cout<<res<<endl;
    return 0;
    
}