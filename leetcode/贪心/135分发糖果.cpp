老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻的孩子中，评分高的孩子必须获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

示例 1:

输入: [1,0,2]
输出: 5
解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n,1),right(n,1);
        for(int i = 1;i<n;i++){
            if(ratings[i]>ratings[i-1])left[i] = left[i-1]+1;
        }
        int count = left[n -1];
        for(int i = n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1])right[i] = right[i+1]+1;
            count +=max(left[i],right[i]);
        }
        return count;
    }
};