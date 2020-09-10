给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

示例:

输入:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
输出: 6

class Solution {
public:
    int maxArea(vector<int>&matrix){
        stack<int>s;
        s.push(0);
        int max_area = 0;
        for(int i =0;i<matrix.size();i++){
            while(!s.empty() && matrix[i]<=matrix[s.top()]){
                int top = s.top();
                s.pop();
                max_area = max(max_area,matrix[top]*(s.empty()?i:i-s.top()-1));
            }
            s.push(i);
        }
        matrix.pop_back();
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)return 0;
        int size = matrix[0].size(),max_area = 0;
        vector<int>dp(size,0);
        for(int i =0;i<matrix.size();++i){
            for(int j =0;j<size;++j){
                dp[j] = matrix[i][j] == '1'?dp[j]+1:0;
            }
            max_area = max(max_area,maxArea(dp));
        }
        return max_area;
    }
};