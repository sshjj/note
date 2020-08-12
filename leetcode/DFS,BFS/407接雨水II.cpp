给你一个 m x n 的矩阵，其中的值均为非负整数，代表二维高度图每个单元的高度，请计算图中形状最多能接多少体积的雨水。

示例：

给出如下 3x6 的高度图:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

返回 4 。

class Solution {
public:
    typedef pair<int,pair<int,int>>PIII;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<PIII,vector<PIII>,greater<PIII>>pq;
        int n = heightMap.size(),m = heightMap[0].size();
        vector<vector<bool>>st(n,vector<bool>(m,false));
        if(n == 1 || m ==1)return 0;
        for(int i = 0;i<m;i++){
            st[0][i] =true;
            st[n-1][i] = true;
            pq.push({heightMap[0][i],{0,i}});
            pq.push({heightMap[n-1][i],{n-1,i}}); 
        }
        for(int i = 0;i<n-1;i++){
            st[i][0] = true;
            st[i][m-1] = true;
            pq.push({heightMap[i][0],{i,0}});
            pq.push({heightMap[i][m-1],{i,m-1}});
        }
        int ans = 0;
        while(pq.size()){
            auto it = pq.top();
            pq.pop();
            for(int i =0;i<4;i++){
                int x = it.second.first+dx[i],y = it.second.second+dy[i];
                if(x>=0 && x<n && y>=0 && y<m && !st[x][y]){
                    ans+=max(0,it.first-heightMap[x][y]);
                    st[x][y] = true;
                    pq.push({max(it.first,heightMap[x][y]),{x,y}});
                }
            }
        }
        return ans;
    }
};