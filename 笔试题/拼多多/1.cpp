#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,n;
    cin>>k>>n;
    if(k == 0){
       cout<<"paradox"<<endl;
       return 0;
    }
    vector<int> p;
    for(int i = 0;i<n;i++){
        int tmp;
        cin>>tmp;
        p.push_back(tmp);
    }
    int res = 0,back = 0;
    for(int i = 0;i<n;i++){
        res+=p[i];
        if(res == k && i!=n ){
            cout<<"paradox"<<endl;
            return 0;
        }
        if(res>k){
            res -=p[i];
            back++;
        }
    }
    res = k-res;
    cout<<res<<' '<<back;
    return 0;
}


//

#include<bits/stdc++.h>
using namespace std;
const int maxn=200;
int a[maxn];
int main(){
    int k,n;
    scanf("%d%d",&k,&n);
    int flag=0, step=0, ret=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(step==k)flag=1;
        step+=a[i]; 
        if(step>k){
            step=2*k-step;
            ret+=1;
        }
    }
    if(flag==1)printf("paradox\n");
    else printf("%d %d\n", k-step, ret);
    return 0;

}