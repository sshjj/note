#include<bits/stdc++.h>
using namespace std;
int  strlength(string s1,string s2){
    if(s1.size()>s2.size())return strlength(s2,s1);
    int m = s1.size(),n = s2.size(),ans = 0;
    for(int i = 0;i<m;i++){
        for(int j = i+1;j<m;j++){
            string tmp = s1.substr(i,j-i+1);
            if(s2.find(tmp)!= s2.npos)ans = max(ans,tmp.size());
        }
    }
}