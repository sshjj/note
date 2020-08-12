给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0)return ;
        int n = board.size(),m = board[0].size();
        for(int i =0;i<n;i++){
            dfs(board,i,0);
            dfs(board,i,m-1);
        }
        for(int i = 0;i<m;i++){
            dfs(board,0,i);
            dfs(board,n-1,i);
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == 'A'){
                    board[i][j] = 'O';
                }else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
    void dfs(vector<vector<char>>&board,int x,int y){
        if(x<0||x>=board.size()||y<0||y>=board[0].size()||board[x][y] != 'O')return ;
        board[x][y] = 'A';
        int dx[4] = {-1,0,1,0},dy[4]= {0,1,0,-1};
        for(int i = 0;i<4;i++){
            int nx = x+dx[i],ny = y+dy[i];
            if(nx>=0&&nx<board.size()&&ny>=0&&ny<board[0].size() && board[nx][ny] == 'O'){
                dfs(board,nx,ny);
            }
        }
    }
};