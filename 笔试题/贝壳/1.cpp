#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans=0;cin>>n;
    string s;cin>>s;
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-1-i]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}