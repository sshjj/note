给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false
 
class Solution {
public:
    int n,m;
    int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty()) return false;
        n = board.size(), m= board[0].size();
        
        for(int i =0;i<n;i++)
            for(int j = 0;j<m;j++)
                if(dfs(board,i,j,word,0))
                    return true;
        return false ;
    }
    bool dfs(vector<vector<char>>& board ,int x, int y,string& word,int u)
    {
        if(board[x][y] != word[u])return false;
        if(u== word.size() - 1)return true;

        board[x][y] = '.';
        for(int i = 0;i<4 ;i++)
        {
            int a = x + dx[i] ,b= y + dy[i];
            if(a >=0 && a<n && b>= 0 && b<m)
                if(dfs(board,a,b,word,u+1))
                    return true;
        }
        board[x][y] = word[u];
        return false;
    }
    
};