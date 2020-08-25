#include<bits/stdc++.h>
using namespace std;
int s(int a){
    int res =0;
    while(a){
        res+=a%10;
        a/=10;
    }
    return res;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int val = 0;
        for(int i =0;i<n/2;i++){
            int res = s(i)+s(n-i);
            val = max(val,res);
            cout<<i<<' '<<n-i<<' '<< res<<endl;
        }
        cout<<val<<endl;
    }
    system("pause");
    return 0;
}