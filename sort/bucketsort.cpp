#include<bits/stdc++.h>
using namespace std;
void bksort(float A[],int l,int h){
    int size = h-l+1;
    vector<float>b[size]；
    for(int i = l;i<=h;i++){
        int bi = size*A[i];
        b[bi].push_back(A[i]);
    }
    for(int i = 0;i<size;i++)
        sort(b[i].begin(),b[i].end());  
    int idx = l;
    for(int i = 0;i<size;i++){
        for(int j = 0;j<b[i].size();j++){
            A[idx++] = b[i][j];
        }
    }
}