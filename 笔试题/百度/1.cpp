#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int l,n;
        cin>>l>>n;
        vector<int>tmp(l+1,0);
        while(n--){
            int l,r;
            cin>>l>>r;
            for(int i = l;i<=r;i++){
                tmp[i]++;
            }
        }
        for(int i =1;i<=l;i++){
            cout<<tmp[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}