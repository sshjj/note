#include<bits/stdc++.h>
using namespace std;
int main(){
    int t ;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        long long sz = n*m;
        if(sz %2 ==0){
            cout<<2<<endl;
            continue;
        }
        int maxv = n>m?n:m;
        if(maxv<9){
            cout<<min(n,m)<<endl;
            continue;
        }
        for(int i = 3;i<=(int)sqrt(maxv);i++){
            if(n%i ==0 || m%i == 0){
                cout<<i<<endl;
                break;
            }
        }
    }
    system("pause");
    return 0;
}