#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v1, v2;
    vector<int> a1, a2;
    cin >> v1;
    a1.push_back(v1);
    while (cin.get() != '\n')
    {
        cin >> v1;
        a1.push_back(v1);
    }
    cin >> v2;
    a2.push_back(v2);
    while (cin.get() != '\n')
    {
        cin >> v2;
        a2.push_back(v2);
    }
    if(!a1.size() || !a2.size()){
        cout<<-1<<endl;
        return 0;
    }
    int res = INT_MAX;
    int sum = 0;
    int min_data = 0;
 
    for(int i =0;i<a1.size()-1;i++){
        for(int j = i+1;j<a2.size();j++){
            sum = a1[i]+a2[j];
            res = min(sum,res);
        }
            
    }
    cout<<res<<endl;
    system("pause");
    return 0;
}