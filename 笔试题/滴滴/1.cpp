#include <bits/stdc++.h>
using namespace std;

void DFS(int i,vector<int>&visited,int n,vector<vector<int>>&arc)
{
	int j;
	visited[i]=1;
	for(j=0;j<n;++j)
	{
		if(arc[i][j]==1&&!visited[j])
			DFS(j,visited,n,arc);
	}
}
void DFSTraverse(vector<vector<int>>&arc,vector<int>&visited,int n)
{
	int i;
	for(i=0;i<n;++i)
	{
		visited[i]=0;
	}
	for(i=0;i<n;++i)
	{
		if(!visited[i])
			DFS(i,visited,n,arc);
	}
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        if(m<n-1){
            cout<<"No"<<endl;
            continue;
        }
        vector<vector<int>> arc(n,vector<int>(n,0));
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            if(k<=z){
                arc[x][y] = arc[y][x] = 1;
            }
        }
        vector<int>visited(n,0);
        DFSTraverse(arc,visited,n);
        for(int i = 0;i<visited.size();i++){
            if(visited[i]==0){
                cout<<"false"<<end;
                break;
            }
        }
        cout<<"true"<<endl;
    }
    system("pause");
    return 0;
}