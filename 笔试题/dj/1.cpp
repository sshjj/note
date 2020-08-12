#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,A,X;
    cin >> N>>A>>X;
    vector<int>time(N,0);
    double sum = 0.0;
    for(int i =0;i<N;i++){
        cin>>time[i];
        sum+=time[i];
    }
    while(N--){
        int i;
        cin>>i;
        time.push_back(i);
        sum+=i;
    }
    if(sum>60*A*X){
    	int res = ceil(sum-60*(A-1)*X);
    	if(res>480 ){
            cout<< 0;
        }
		else{
       		cout<< res;
       	}
    }
    else{
        int res = ceil(sum/A);
        if(res>480){
            cout<< 0;
        }
        else{
            cout<< res;
        }
    }
    system("pause");
    return 0;

}