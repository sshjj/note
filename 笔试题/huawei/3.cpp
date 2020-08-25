#include <bits/stdc++.h>
using namespace std;

void solve(){
    string str1,str2;
    cin>>str1>>str2;
    int n=str1.size();
    int m=str2.size();
    int ret = 1e9;
    for(int i=0;i<n-m+1;i++){
        int max_hei = 0;
        int tmp_hei = 0;
        for(int j=0;j<m;j++){
            int tmp = str1[i+j] - '0' + str2[j] - '0';
            max_hei = max(max_hei,tmp);
            tmp_hei = max(tmp_hei , tmp);
        }
        for(int j=0;j<n;j++)max_hei = max(max_hei,str1[j] - '0');
        int cut_len = 1e9;

        for(int j=0;j<n;j++){
            if(j<i)cut_len = min(cut_len,str1[j] - '0');
            else if(j>=i && j<=i+m-1){
                int len;
                if(str2[j-i] - '0' + str1[j] - '0' == tmp_hei)len=tmp_hei;
                else len = str1[j] - '0';
                cut_len = min(cut_len,len);
            }else cut_len = min(cut_len,str1[j] - '0');

        }
        ret = min(ret,max_hei-cut_len);
    }
    cout<<ret<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
	return 0;
}