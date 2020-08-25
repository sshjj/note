#include <bits/stdc++.h>
using namespace std;

int MinTime(vector<int>a, int n)
{
    sort(a.begin(), a.begin() + n);
    n--;
    int mintime = 0;
    while (n > 2)
    {
        mintime += min(a[0] + a[1] * 2 + a[n], a[0] * 2 + a[n] + a[n - 1]);
        n -= 2;
    }
    if (n == 0)
    {
        mintime = a[0];
    }
    else if (n == 1)
    {
        mintime += a[1];
    }
    else
    {
        mintime += a[0] + a[1] + a[2];
    }
    return mintime;
}
int main()
{
    int n, m;
    cin >> n;
    int v;
    vector<int> a;
    while (n--)
    {
        cin >> v;
        a.push_back(v);
    }
    cin >> m;
    int time;
    time=MinTime(a, n);
    if(time>m)cout<<0<<endl;
    else cout<<1<<endl;
    system("pause");
    return 0;
}
