给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例:

输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。

//递归+回溯 
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择


class Solution {
public:
    vector<vector<string>>res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        backtrack(board,0);
        return res;
    }
    void backtrack(vector<string>&board,int row){
        if(row == board.size()){
            res.push_back(board);
            return;
        }
        int n = board[row].size();
        for(int col = 0;col<n;col++){
            if(!isValid(board,row,col))
                continue;
            board[row][col] = 'Q';
            backtrack(board,row+1);
            board[row][col] = '.';
        }
    }
    bool isValid(vector<string>& board,int row,int col){
        int n = board.size();
        for(int i = 0;i<n;i++){
            if(board[i][col] == 'Q')
                return false;
        }
        for(int i = row-1,j = col+1;i>=0&&j<n;i--,j++){
            if(board[i][j]=='Q')
                return false;
        }
        for(int i = row-1,j = col-1;i>=0&&j>=0;i--,j--){
            if(board[i][j]=='Q')
                return false;
        }
        return true;
    }
};