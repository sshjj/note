#include<bits/stdc++.h>
using namespace std;

bool ispa(string str,int l,int r){
    int len=r-l+1;
    for(int i=0;i<len/2;i++){
        if(str[i]!=str[len-1-i]) return false;
    }
    return true;
}

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    if(ispa(s,0,n-1)) cout<<s<<endl;
    else{
        string tmp="";
        for(int i=0;i<n;i++){
            tmp=s[i]+tmp;
            if(ispa(s+tmp,0,n+i)){
                cout<<s+tmp<<endl;
                return 0;
            }
        }
    }
    return 0;
}