#include<bits/stdc++.h>
using namespace std;
map<int,int>q;
int a[10];
int num=1e9;
void dfs(int b[], int step){
    if(step==6)return;
    int tmp=0;
    for(int i=1;i<=6;i++)
        tmp=tmp*10+b[i];
    num=min(num,tmp);
    for(int i=1;i<=6;i++){
        int c[10];
        if(i==1){
            c[1]=b[1];c[2]=b[2];c[3]=b[5];c[4]=b[6];c[5]=b[4];c[6]=b[3];
        }
        else if(i==2){
            c[1]=b[1];c[2]=b[2];c[3]=b[4];c[4]=b[3];c[5]=b[6];c[6]=b[5];
        }
        else if(i==3){
            c[1]=b[1];c[2]=b[2];c[3]=b[6];c[4]=b[5];c[5]=b[3];c[6]=b[4];
        }
        else if(i==4){
            c[1]=b[6];c[2]=b[5];c[3]=b[3];c[4]=b[4];c[5]=b[1];c[6]=b[2];
        }
        else if(i==5){
            c[1]=b[2];c[2]=b[1];c[3]=b[3];c[4]=b[4];c[5]=b[6];c[6]=b[5];
        }
        else if(i==6){
            c[1]=b[5];c[2]=b[6];c[3]=b[3];c[4]=b[4];c[5]=b[2];c[6]=b[1];
        }
        dfs(c, step+1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=1;j<=6;j++)
            scanf("%d",&a[j]);
        num=1e9;
        dfs(a, 0);
        q[num]+=1;
    }
    map<int, int>::iterator it;
    priority_queue<int>que;
    for(it=q.begin();it!=q.end();it++){
        que.push(it->second);
    }
    printf("%d\n%d",que.size(), que.top());
    que.pop();
    while(!que.empty()){
        printf(" %d",que.top());
        que.pop();
    }
    printf("\n");
    return 0;
}