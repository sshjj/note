编写一个程序，通过已填充的空格来解决数独问题。

一个数独的解法需遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。

class Solution {
public:
    bool sovled  = false;
    bool row[9][10] = {0},col[9][10] = {0},box[9][10]= {0};
    void solveSudoku(vector<vector<char>>& board) { 
        for(int i =0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(board[i][j] == '.')continue;
                int index = 3*(i/3)+j/3;
                int num = board[i][j]- '0';
                row[i][num] = col[j][num] =box[index][num] =true;
            }
        }
        backtrack(0,0,board);
    }
    void backtrack(int i,int j,vector<vector<char>>& board){
        if(sovled == true)return ;
        if(i>=9){sovled = true;return;}
        if(board[i][j] != '.'){
            if(j<8)
                backtrack(i,j+1,board);
            else if(j == 8)
                backtrack(i+1,0,board);
            if(sovled == true)
                return ;
        }
        else{
            int index = 3*(i/3) + j/3;
            for(int num = 1;num<=9;num++){
                if(!row[i][num]&&!col[j][num]&&!box[index][num]){
                    board[i][j] = num+'0';
                    row[i][num] = col[j][num] = box[index][num] = true;
                    if(j<8)
                        backtrack(i,j+1,board);
                    else if(j == 8)
                        backtrack(i+1,0,board);
                    if(!sovled){
                        row[i][num] = col[j][num] = box[index][num] =  false;
                        board[i][j] = '.';
                    }
                }
            }
        }
    }
};