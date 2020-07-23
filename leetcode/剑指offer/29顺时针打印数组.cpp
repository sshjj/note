
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();
        if(!n)return res;
        int m = matrix[0].size();
        vector<vector<bool>>st(n,vector<bool>(m,false));
        int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
        int x = 0,y = 0,d = 1;
        for(int i = 0;i<n*m;i++){
            res.push_back(matrix[x][y]);
            st[x][y] = true;
            int a = x+dx[d],b= y+dy[d];
            if(a<0||a>=n||b<0||b>=m||st[a][b]){
                d = (d+1)%4;
                a = x+dx[d],b = y+dy[d];
            }
            x =a ,y=b;
        }
        return res;
    }
};