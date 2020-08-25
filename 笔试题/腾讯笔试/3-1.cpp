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
        int val = 0,cnt = 0;
        int nn = n;
        if(n<10){cout<<s(n)<<endl;continue;}
        while(nn){
            cnt++;
            nn/=10;
        }
        int num = 9;
        cnt=cnt-1;
        while(--cnt){
            num = num*10+9;
        }
        val = s(num)+s(n-num);
        cout<<val<<endl;
    }
    system("pause");
    return 0;
}