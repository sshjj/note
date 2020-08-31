#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    int i =0,j = n-1;
    string ans;
    while(i<n && str[i]!='M')i++;
    if(str[i]=='M'){
        while(i<n && str[i]!='T')i++;
    }
    i++;
    while(j>=i && str[j]!='T')j--;
    if(str[j] == 'T'){
        while(j>=i && str[j]!='M')j--;
    }
    ans = str.substr(i,j-i);
    cout<<ans<<endl;
    return 0;
}