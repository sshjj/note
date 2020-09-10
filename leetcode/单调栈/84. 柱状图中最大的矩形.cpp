给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

输入: [2,1,5,6,2,3]
输出: 10

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        int ans = 0;
        heights.push_back(0);
        for(int i =0;i<heights.size();++i){
            while(!s.empty() &&heights[s.top()]>=heights[i]){
                int h  = heights[s.top()];
                s.pop();
                if(s.empty()){
                    ans = max(ans,i*h);
                }
                else{
                    ans = max(ans,(i-s.top()-1)*h);
                }
            }
            s.push(i);
        }
        return ans;
    }
};