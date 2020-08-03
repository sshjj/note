#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<pair<int, int>> lunch{{0, 0}};
    vector<pair<int, int>> super{{0, 0}};
    for(int i = 0; i < n + m; ++i) {
        int a, b;
        cin >> a >> b;
        if(i < n)
            lunch.push_back({b, a});
        else
            super.push_back({b, a});
    }
    sort(lunch.begin(), lunch.end());
    sort(super.begin(), super.end());
    int res = INT_MAX;
    for(int i = 0; i < n; ++i) {
        int l = lunch[i].first, k = lunch[i].second;
        for(int j = m - 1; j >= 0; --j) {
            if(l + super[j].first < t)
                break;
            res = min(res, k + super[j].second);
        }
    }
    if(res == INT_MAX)
        cout << -1 << endl;
    else
        cout << res << endl;
    return 0;
}