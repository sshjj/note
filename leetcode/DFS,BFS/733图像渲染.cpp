有一幅以二维整数数组表示的图画，每一个整数表示该图画的像素值大小，数值在 0 到 65535 之间。

给你一个坐标 (sr, sc) 表示图像渲染开始的像素值（行 ，列）和一个新的颜色值 newColor，让你重新上色这幅图像。

为了完成上色工作，从初始坐标开始，记录初始坐标的上下左右四个方向上像素值与初始坐标相同的相连像素点，接着再记录这四个方向上符合条件的像素点与他们对应四个方向上像素值与初始坐标相同的相连像素点，……，重复该过程。将所有有记录的像素点的颜色值改为新的颜色值。

最后返回经过上色渲染后的图像。

示例 1:

输入: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
输出: [[2,2,2],[2,2,0],[2,0,1]]
解析: 
在图像的正中间，(坐标(sr,sc)=(1,1)),
在路径上所有符合条件的像素点的颜色都被更改成2。
注意，右下角的像素没有更改为2，
因为它不是在上下左右四个方向上与初始点相连的像素点。

class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if(color!=newColor){
            dfs(image,sr,sc,newColor,color);
        }
        return image;
    }
    void dfs(vector<vector<int>>& image,int x,int y,int newColor,int color){
        if(image[x][y] != color)return ;
        image[x][y] = newColor;
        for(int i =0;i<4;i++){
            int nx = x+dx[i],ny = y+dy[i];
            if(nx>=0 && nx<image.size() && ny>=0 && ny<image[0].size())
                dfs(image,nx,ny,newColor,color);
        }
    }
};


class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if(color==newColor)return image;
        int n = image.size(),m = image[0].size();
        queue<pair<int,int>>q;
        q.emplace(sr,sc);
        image[sr][sc] = newColor;
        while(!q.empty()){
            int x = q.front().first,y = q.front().second;
            q.pop();
            for(int i =0;i<4;i++){
                int mx = x+dx[i],my = y+dy[i];
                if(mx>=0 && mx<n&&my>=0&&my<m&&image[mx][my] == color){
                    q.emplace(make_pair(mx,my));
                    image[mx][my] = newColor;
                }
            }
        }
        return image;
    }
};