#include<bits/stdc++.h>
using namespace std;
int main(){
    int v1;
    vector<int> a1;
    cin >> v1;
    a1.push_back(v1);
    while(cin.get() != '\n')
    {
        cin >> v1;
        a1.push_back(v1);
    }
    sort(a1.begin(),a1.end());
    for(int i = 0;i<a1.size()-1;i++){
        cout<<a1[i]<<' ';
    }
    cout<<a1[a1.size()-1];
    system("pause");
    return 0;
}

