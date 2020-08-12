给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

 

示例 1:

输入:
[
['1','1','1','1','0'],
['1','1','0','1','0'],
['1','1','0','0','0'],
['0','0','0','0','0']
]
输出: 1

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size())return 0;
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>mark(n,vector<int>(m,0));
        for(int i = 0;i<n;++i){
            for(int j = 0;j<m;++j){
                if(grid[i][j] == '1' && mark[i][j] == 0){
                    dfs(mark,grid,i,j);
                    res++;
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>&mark,vector<vector<char>>&grid,int x,int y){
        int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
        mark[x][y] = 1;
        for(int i = 0;i<4;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(newx<0 || newx>=mark.size()||newy<0||newy>=mark[0].size())continue;
            if(mark[newx][newy] == 0 && grid[newx][newy] == '1'){
                dfs(mark,grid,newx,newy);
            }
        }
    }
};


//bfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size())return 0;
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>mark(n,vector<int>(m,0));
        for(int i = 0;i<n;++i){
            for(int j = 0;j<m;++j){
                if(grid[i][j] == '1' && mark[i][j] == 0){
                    bfs(mark,grid,i,j);
                    res++;
                }
            }
        }
        return res;
    }
    void bfs(vector<vector<int>>&mark,vector<vector<char>>&grid,int x,int y){
        int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
        queue<pair<int,int>>q;
        q.push(make_pair(x,y));
        mark[x][y] = 1;
        while(!q.empty()){
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++){
                int newx = x+dx[i];
                int newy = y+dy[i];
                if(newx<0 || newx>=mark.size()||newy<0||newy>=mark[0].size())continue;
                if(mark[newx][newy] == 0 && grid[newx][newy] == '1'){
                    q.push(make_pair(newx,newy));
                    mark[newx][newy] = 1;
                }
            }
        }
    }
};