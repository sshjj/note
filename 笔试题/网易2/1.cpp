#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> tree(m, vector<int>(2, 0));
    int a, b;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> s >> b;
        if (s == "left")
        {
            tree[a][0] = b;
        }
        if (s == "right")
        {
            tree[a][1] = b;
        }
    }
    int res = 0;
    for (int i = 0; i < m; i++)
    {
        if (tree[tree[i][0]][0] == 0 && tree[tree[i][0]][1] == 0 && tree[tree[i][1]][0] == 0 && tree[tree[i][1]][1] == 0)
            res++;
    }
    cout << res << endl;
    system("pause");
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> g[n + 1];
    while (m--)
    {
        int a, b;
        string x;
        cin >> a >> x >> b;
        g[a].push_back(b);
    }
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (g[i].size() == 2 && g[g[i][0]].empty() && g[g[i][1]].empty())
        {
            ++res;
        }
    }
    cout << res << endl;
    return 0;
}