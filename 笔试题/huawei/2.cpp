#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
int f(int n){
    int ans=1;
    for(int i=2;i<=n;i++){
        ans*=i;
        ans%=MOD;
    }
    return ans;
}
int ksm(int a,int b){
    int ans=1,base=a;
    while(b){
        if(b&1) ans=(ans*base)%MOD;
        b>>=1;
        base=(base*base)%MOD;
    }
    return ans;
}
int C_a_b(int n,int m){
    if(m==0) return 1;
    if(n<=m) return 1;
    int t1,t2,res;
    t1=f(n);
    t2=(f(m)*f(n-m))%MOD;
    t2=ksm(t2,MOD-2);
    res=(t1*t2)%MOD;
    return res;
}

int32_t main()
{
    int N;cin>>N;
    vector<int> depth(N,0);
    for(int i=0;i<N;i++) cin>>depth[i];
    sort(begin(depth),end(depth));
    unordered_map<int,int> h;
    for(auto n:depth) h[n]++;
    int ans=1;
    for(int i=1;i<depth[N-1];i++){
        int pre=pow(2,h[i-1]);
        if(h[i]==pre) continue;
        else if(h[i]>pre){
            cout<<0<<endl;
            return 0;
        }
        else{
            ans=(ans*C_a_b(pre,pre-h[i]))%MOD;
        }
    }
    cout<<ans<<endl;
}