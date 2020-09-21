#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    unordered_map<int, int> m{{0, -1}};
    int res = 0, n = s.length(), cur = 0;
    for (int i = 0; i < n; i++) {
        cur ^= 1 << string("abcxyz").find(s[i]) + 1 >> 1;
        if (!m.count(cur)) m[cur] = i;
        res = max(res, i - m[cur]);
    }
    cout<< res <<endl;
    return 0;
}