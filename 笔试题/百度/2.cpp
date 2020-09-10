#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<int> A(n);
        for(int i = 0; i < n; ++i)
            cin >> A[i];
        map<int, vector<int>> mp;
        for(int i = 1; i <= m; ++i) {
            int x; cin >> x;
            mp[x].push_back(i);
        }
        for(auto x : A) {
            auto it = mp.lower_bound(x);
            if(it == mp.end()) {
                cout << -1 << " ";
            }
            else {
                cout << it->second.back() << " ";
                it->second.pop_back();
                if(it->second.size() == 0)
                    mp.erase(it);
            }
        }
    }
    return 0;
}