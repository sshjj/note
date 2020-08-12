#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin>>n;
    vector<int>nums(n,0);
    int maxn = 0,max_num = 0,index = 0;;
    for(int i = 0;i<n;i++){
        cin>>nums[i];
        maxn |=nums[i];
        }
    }
    int res = INT_MAX,cursum = 0;
    for(int i = 0,j =0;i<n;i++){
        while(cursum == maxn){
            j++;
            res = min(res,i-j+1);
        }
        cursum |=nums[i];

    }

}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i;
    cin >> n;
    vector<int> nums(n);
    int totOr = 0;
    for (i = 0; i < n; ++i)
    {
        cin >> nums[i];
        totOr |= nums[i];
    }
    int curOr = 0, l = 0, r = 0;
    int ret = INT_MAX;
    while (r < n)
    {
        curOr |= nums[r];
        if (curOr == totOr)
        {
            ret = min(ret, r - l + 1);
            l = r + 1;
            curOr = 0;
        }
        ++r;
    }
    curOr = 0, l = r = n - 1;
    while (l >= 0)
    {
        curOr |= nums[l];
        if (curOr == totOr)
        {
            ret = min(ret, r - l + 1);
            r = l - 1;
            curOr = 0;
        }
        --l;
    }
    cout << ret;
}

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> elements(n);
    int or_sum = 0;
    for (int i = 0; i < n; i += 1) {
        cin >> elements[i];
        or_sum |= elements[i];
    }

    vector<int> last_seen(32, -1);
    int answer = n; // the min length of a segment that has the OR sum equal to the global one (or_sum)
    for (int i = 0; i < n; i += 1) {
        // add current element
        for (int j = 0; j < 30; j += 1) {
            if (elements[i] & (1 << j)) {
                last_seen[j] = i;
            }
        }

        // get min last_seen that is != 1 and compute current OR sum
        int mn_last_seen = i; // all elements will be <= i for sure
        int current_or = 0;
        for (int j = 0; j < 30; j += 1) {
            if (last_seen[j] != -1) {
                mn_last_seen = min(mn_last_seen, last_seen[j]);
                current_or |= (1 << j);
            }
        }

        if (current_or == or_sum) {
            answer = min(answer, i - mn_last_seen + 1);
        }
    }

    cout << answer << '\n';
    return 0;
}
