#include <bits/stdc++.h>
using namespace std;
int merge(vector<int>&nums,int l,int r){
        if(l>=r)return 0;
        int mid = (l+r)>>1;
        int res = merge(nums,l,mid)+merge(nums,mid+1,r);
        int i = l,j = mid+1;
        for(int k = l;k<=r;k++){
            if(i<=mid && (j>r || nums[i]<=nums[j])){
                tmp[k] = nums[i++];
            }
            else{
                tmp[k] = nums[j++];
                res += mid - i +1;
            }
        }
        for(int i = l;i<=r;i++)nums[i] = tmp[i];
        return res;
    }
void dfs(vector<int> &nums, int idi, int &res)
{
    if(idi == nums.size()-2)return ;
    for(int i = nums.size();i>=0;i--){
        if(abs(nums[i])>abs(nums[idi])){
            for(int j = idi+1;j<i;j++){
                if(abs(nums[j])>abs(nums[i])){
                    res++;
                }
            }
        }
    }
    dfs(nums, idi+1, res);
}
int numthree(vector<int> nums)
{
    int res = 0;
    dfs(nums, 0, res);
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    int res = numthree(data) % 100000007;
    cout << res << endl;
    system("pause");
    return 0;
}
