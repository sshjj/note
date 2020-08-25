#include<bits/stdc++.h>
using namespace std;
int main(){
    int v1,v2;
    vector<int> a1,a2;
    cin >> v1;
    a1.push_back(v1);
    while(cin.get() != '\n')
    {
        cin >> v1;
        a1.push_back(v1);
    }
    cin >> v2;
    a2.push_back(v2);
    while(cin.get() != '\n')
    {
        cin >> v2;
        a2.push_back(v2);
    }
    vector<int>res;
    for(int i = 0;i<a2.size();i++){
        for(int j =0 ;j<a1.size();j++){
            if(a2[i] == a1[j])
                res.push_back(a2[i]);

        }
    }
    unordered_map<int,int>hash;
    for(auto x:a2)hash[x]++;
    for(int i =0;i<a1.size();i++){
        if(hash.count(a1[i])>0){
            hash[a1[i]]--;
        }
        else{
            res.push_back(a1[i]);
        }
    }
    for(int i =0 ;i<res.size();i++){
        cout<<res[i]<<' ';
    }
    //system("pause");
    return 0;
}