给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。
示例:
输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0){
            return 0;
        }
        int r = grid.size(),c = grid[0].size();
        vector<vector<int>> dp(r,vector<int>(c));
        dp[0][0] = grid[0][0];
        for(int i = 1;i< r;i++){
            dp[i][0] = dp[i-1][0]+grid[i][0];
        }
        for(int i = 1;i<c;i++){
            dp[0][i] = dp[0][i-1]+grid[0][i];
        }
        for(int i =1;i<r;i++){
            for(int j =1;j<c;j++){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[r-1][c-1];
        
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>

#include <vector>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int> >& grid) {
    	if (grid.size() == 0){
	    	return 0;
	    }
	    int row = grid.size();
    	int column = grid[0].size();
    	std::vector<std::vector<int> > 
						dp(row, std::vector<int>(column, 0));
    	
	    dp[0][0] = grid[0][0];
	    for (int i = 1; i < column; i++){
    		dp[0][i] = dp[0][i-1] + grid[0][i];
    	}
	    for (int i = 1; i < row; i++){
	    	dp[i][0] = dp[i-1][0] + grid[i][0];
    		for (int j = 1; j < column; j++){
		    	dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
		    }
    	}
	    return dp[row-1][column-1];
    }
};

int main(){
	int test[][3] = {{1,3,1}, {1,5,1}, {4,2,1}};
	std::vector<std::vector<int> > grid;
	for (int i = 0; i < 3; i++){
		grid.push_back(std::vector<int>());
		for (int j = 0; j < 3; j++){
			grid[i].push_back(test[i][j]);
		}
	}
	Solution solve;
	printf("%d\n", solve.minPathSum(grid));	
	return 0;
}