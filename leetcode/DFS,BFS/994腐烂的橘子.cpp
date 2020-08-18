在给定的网格中，每个单元格可以有以下三个值之一：

值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。

返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。

 

示例 1：
输入：[[2,1,1],[1,1,0],[0,1,1]]
输出：4
示例 2：

输入：[[2,1,1],[0,1,1],[1,0,1]]
输出：-1
解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。

class Solution {
public:
    int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int m =grid.size(),n = grid[0].size();
        int res = 0;
        queue<pair<int,int>>q;
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 2)q.push({i,j});
            }
        }
        while(!q.empty()){
            int s = q.size();
            for(int i =0;i<s;i++){
                pair<int,int>p = q.front();
                q.pop();
                for(int j = 0;j<4;j++){
                    int x = p.first+dx[j],y = p.second+dy[j];
                    if(x>=0 && x<m&& y>=0 && y<n&&grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x,y});
                    }
                }
            }
            if(!q.empty())res++;
        }
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return res;
    }
};