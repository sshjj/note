#include<bits/stdc++.h>
using namespace std;
const int maxn=10;
const int mod=1e9+9;
char c[maxn][maxn];
int a[maxn][maxn];
int ans=0;
vector<pair<int,int> >q;
int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
bool check(){
    for(int k=0;k<(int)q.size();k++){
        int i=q[k].first, j=q[k].second;
        int flag=0;
        for(int z=0;z<4;z++){
            int x=i+dx[z],y=j+dy[z];
            if(x<0||x>5||y<0||y>5||c[x][y]=='*')continue;
            if(a[i][j]==a[x][y])flag=1;
        }
        if(flag==1)return 0;
    }
    return 1;
}
void dfs(int pos){
    if(pos==(int)q.size()){
        if(check())
            ans++;
        return ;
    }
    for(int i=1;i<=6;i++){
        a[q[pos].first][q[pos].second]=i;
        dfs(pos+1);
    }
}
int main(){
    for(int i=0;i<6;i++)
    {
        scanf("%s",c[i]);
        for(int j=0;j<6;j++)
            if(c[i][j]=='#')q.push_back(make_pair(i, j));
    }
    dfs(0);
    printf("%d\n",ans);
}