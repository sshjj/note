在 x 轴上有一个一维的花园。花园长度为 n，从点 0 开始，到点 n 结束。

花园里总共有 n + 1 个水龙头，分别位于 [0, 1, ..., n] 。

给你一个整数 n 和一个长度为 n + 1 的整数数组 ranges ，其中 ranges[i] （下标从 0 开始）表示：如果打开点 i 处的水龙头，可以灌溉的区域为 [i -  ranges[i], i + ranges[i]] 。

请你返回可以灌溉整个花园的 最少水龙头数目 。如果花园始终存在无法灌溉到的地方，请你返回 -1 。

输入：n = 5, ranges = [3,4,1,1,0,0]
输出：1
解释：
点 0 处的水龙头可以灌溉区间 [-3,3]
点 1 处的水龙头可以灌溉区间 [-3,5]
点 2 处的水龙头可以灌溉区间 [1,3]
点 3 处的水龙头可以灌溉区间 [2,4]
点 4 处的水龙头可以灌溉区间 [4,4]
点 5 处的水龙头可以灌溉区间 [5,5]
只需要打开点 1 处的水龙头即可灌溉整个花园 [0,5] 。


题解：

贪心法
1：首先遍历rangs，建立45. 跳跃游戏 Ⅱ中的跳跃数组，left表示起始点，right-left表示最大跳跃距离
2：使用跳跃游戏Ⅱ中的代码即可，不过每次到达边界end，需判断furthest是否超过end


class Solution {
public:
    //题解：贪心法
    //1：首先遍历rangs，建立跳跃游戏Ⅱ中的跳跃数组，left表示起始点，right-left表示最大跳跃距离
    //2：使用跳跃游戏Ⅱ中的代码即可，不过每次到达边界end，需判断furthest是否超过end
    int minTaps(int n, vector<int>& ranges) {
        //1、建立跳跃数组
        vector<int> jumps(n+1);
        for(int i=0;i<n+1;++i){
            int left=max(i-ranges[i],0);
            int right=min(i+ranges[i],n);
            if(jumps[left]<right-left){
                jumps[left]=right-left;
            }
        }
        //2、贪心法跳跃
        int furthest=0,end=0,count=0;
        for(int i=0;i<n;++i){//注意最后一个点不能遍历，因为在i==end==0时，count多统计了一次
            furthest=max(jumps[i]+i,furthest);
            if(furthest>=n){
                count++;
                break;
            }
            if(i==end){
                //若最远距离没有超过边界，直接返回-1
                if(furthest<=end)return -1;
                count++;
                end = furthest;
            }
        }
        return count;
    }
};