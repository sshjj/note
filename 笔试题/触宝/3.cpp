#include <bits/stdc++.h>
using namespace std;
#define MAX 10
int CrossBridge(int a[],int n)
{
    int time;
    if(n==1)
    {
        time=a[0];
        return time;
    }
    else if(n==2)
    {
        time=a[1];
        return time;
    }
    else if(n==3)
    {
        time=a[0]+a[1]+a[2];
        return time;
    }
    else
    {
        if(2*a[1]>a[0]+a[n-2])
        {
            time=2*a[0]+a[n-1]+a[n-2];
        }
        else
        {
            time=a[0]+a[1]+a[n-1]+a[1];
        }
        return time+CrossBridge(a,n-2);
    }
}
int main()
{
    int crossnum,i;
    int t[MAX];
    scanf("%d",&crossnum);
    for(i=0;i<crossnum;i++)
    {
        scanf("%d",&t[i]);
    }
    int m;
    cin>>m;
    int time = CrossBridge(t,crossnum);
    if(m>time)cout<<0<<endl;
    else cout<<1<<endl;
    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve()
{
    int n;
    cin >> n;
    vector<int> arrmv;

    multiset<int> ms;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arrmv.push_back(t);
        ms.insert(t);
    }
    int m;
    cin >> m;
    if (n == 0)
    {
        cout << 1 << endl;
        return;
    }
    if (n == 1)
    {
        cout << ((m >= arrmv[0]) ? 1 : 0) << endl;
        return;
    }
    int ans = 0;
    int side_state = 1;
    int cnt = 0;
    while (ms.size() > 0)
    {
        side_state = !side_state;
        if (side_state == 0)
        {
            if (cnt % 2 == 0)
            {
                int f = *ms.begin();
                ms.erase(ms.begin());
                int s = *ms.begin();
                ms.erase(ms.begin());
                ans += s;
                pq.push(f);
                pq.push(s);
            }
            else
            {
                int f = *ms.rbegin();
                ms.erase(--ms.end());
                int s = *ms.rbegin();
                ms.erase(--ms.end());
                pq.push(f);
                pq.push(s);
                ans += f;
            }
            cnt++;
        }
        else
        {
            ans += pq.top();
            ms.insert(pq.top());
            pq.pop();
        }
    }
    cout << ((m >= ans) ? 1 : 0) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}