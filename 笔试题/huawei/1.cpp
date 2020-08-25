#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    if(n<10 || m<10 || n>1000 || m>1000){
        cout<<"[]"<<endl;
        return 0;
    }
    string res = "[";
    vector<vector<int>>dstep({0,1},{1,0},{0,-1},{-1,0});
    vector<int>step(n,m-1);
    int cnt = 1,x =0,y = -1,d = 0;
    while(step[d%2]){
        for(int i =0;i<step[d%2];i++){
            x+=dstep[d][0],y +=dstep[d][1];
            if(cnt>10 && cnt%10 == 7 &&(cnt/10)%10%2 == 1 ){
                res +="["+to_string(x)+","+to_string(y)+"],";
            }
            cnt++;
        }
        --step[d%2];
        d = (d+1)%4;
    }
    if(res!="["){
        res.back() = "]";
    }else{
        res+="]";
    }
    cout<<res<<endl;
    system("pause");
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    if((m < 10 || m > 1000) || (n < 10) || (n > 1000)) {
        cout << "[]" << endl;
        return 0;
    }
    vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> nSteps{n, m - 1};
    int idir = 0;
    int ir = 0, ic = -1;
    string res = "[";
    int start = 1;
    while(nSteps[idir % 2]) {
        for(int i = 0; i < nSteps[idir % 2]; ++i) {
            ir += dirs[idir][0];
            ic += dirs[idir][1];
            if(start % 10 == 7 && start > 10 && (start / 10) % 10 % 2 == 1)
                res += "[" + to_string(ir) + "," + to_string(ic) + "],";
            ++start;
        }
        --nSteps[idir % 2];
        idir = (idir + 1) % 4;
    }
    if(res != "[")
        res.back() = ']';
    else
        res += "]";
    cout << res << endl;
    return 0;
}