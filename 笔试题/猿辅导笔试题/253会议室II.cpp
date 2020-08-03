/*
给定一个会议时间安排的数组，每个会议时间都会包括开始和结束的时间 [[s1,e1],[s2,e2],…] (si < ei)，为避免会议冲突，同时要考虑充分利用会议室资源，请你计算至少需要多少间会议室，才能满足这些会议安排。

示例 1:

输入: [[0, 30],[5, 10],[15, 20]]
输出: 2
示例 2:

输入: [[7,10],[2,4]]
输出: 1
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<vector<int>>nums(N,vector<int>(2,0));
    for(int i = 0;i<N;i++)cin>>nums[i][0]>>nums[i][1];
    sort(nums.begin(),nums.end());
    priority_queue<int,vector<int>,greater<int>>q;
    for(auto n:nums){
        if(!q.empty() && q.top()<=n[0])q.pop();
        q.push(n[1]);
    }
    cout<< q.size()<<endl;
    system("pause");
    return 0;
}