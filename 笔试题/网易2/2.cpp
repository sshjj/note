#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n = s.size(), ans = 0;
    for (int i = 0; i < n; ++i) {
            int l = i, r = i; 
            while (l >= 0 && r < n && s[l--] == s[r++]) ++ans;
            l = i, r = i + 1; 
            while (l >= 0 && r < n && s[l--] == s[r++]) ++ans;
        }
    cout<< ans - n <<endl;
    return 0;
}