#include<bits/stdc++.h>
using namespace std;
int m,n,Map[31][31],vis[31][31],dx[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
queue<int>q;
bool is_ok(){
    //判断行
    for(int i=0;i<m;i++)
        for (int j = 1; j < n-1; j++) {
            if(Map[i][j-1]==Map[i][j] && Map[i][j]==Map[i][j+1] && Map[i][j]!=0)
                return false;
        }
    //列
    for(int i=0;i<n;i++)
        for(int j=1;j<m-1;j++){
            if(Map[j-1][i]==Map[j][i] && Map[j][i]==Map[j+1][i] && Map[j][i]!=0)
                return false;
        }
    return true;
}
void dfs(int i,int j,int cur){
    //记录节点值一样的位置
    vis[i][j]=1;
    for(int k=0;k<4;k++){
        int tx=i+dx[k][0],ty=j+dx[k][1];
        if(tx<0 || tx>=m || ty<0 || ty>=n || Map[tx][ty]!=cur || vis[tx][ty]) continue;
        dfs(tx,ty,cur);
    }
}
void del(){
    //判断行
    int tmp[31][31]={0};
    for(int i=0;i<m;i++)
        for (int j = 1; j < n - 1; j++) {
            if (vis[i][j - 1] && vis[i][j] && vis[i][j + 1]) tmp[i][j]=1;
        }
    //列
    int tmp1[31][31]={0};
    for(int i=0;i<n;i++)
        for(int j=1;j<m-1;j++){
            if(vis[j-1][i] && vis[j][i] && vis[j+1][i]) tmp1[j][i]=1;
        }
    //统一删除
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++) {
            if (tmp[i][j]) Map[i][j] = Map[i][j-1]=Map[i][j+1]=0;
            if(tmp1[i][j]) Map[i][j] =Map[i-1][j] = Map[i+1][j]=0;
        }
    memset(vis,0,sizeof vis);
}
void down(){
    for(int j=0;j<n;j++){
        vector<int> tmp;
        for(int i=m-1;i>=0;i--) if(Map[i][j]) tmp.push_back(Map[i][j]);
        int k=m-1;
        for(auto t:tmp) Map[k--][j]=t;
        while(k>=0) Map[k--][j]=0;
    }
}
void add(){
    int i=m-1;
    while(i>=0){
        if(q.empty()) break;
        for(int j=0;j<n;j++){
            if(q.empty()) break;
            if(Map[i][j]==0){
                int t=q.front();q.pop();
                Map[i][j]=t;
            }
        }
        i--;
    }
}

int main()
{
    cin>>m>>n;
    string s1,s2;cin>>s1>>s2;
    int k=0;
    for(auto c:s1) {
        Map[k / n][k % n] = (c - '0');
        k++;
    }
    for(auto c:s2) q.push((c-'0'));
    while(1){
        if(q.empty() && is_ok()) break;
        //消消
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++) {
                if(Map[i][j]){
                    dfs(i,j,Map[i][j]);
                    del();
                }
            }
         //下沉　
         down();
         //补充
         if(!q.empty()) add();
    }
    for(int i=0;i<n;i++) cout<<Map[0][i];
    return 0;
}