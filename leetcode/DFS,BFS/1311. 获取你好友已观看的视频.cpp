有 n 个人，每个人都有一个  0 到 n-1 的唯一 id 。

给你数组 watchedVideos  和 friends ，其中 watchedVideos[i]  和 friends[i] 分别表示 id = i 的人观看过的视频列表和他的好友列表。

Level 1 的视频包含所有你好友观看过的视频，level 2 的视频包含所有你好友的好友观看过的视频，以此类推。一般的，Level 为 k 的视频包含所有从你出发，最短距离为 k 的好友观看过的视频。

给定你的 id  和一个 level 值，请你找出所有指定 level 的视频，并将它们按观看频率升序返回。如果有频率相同的视频，请将它们按字母顺序从小到大排列。 

示例 1：

输入：watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 1
输出：["B","C"] 
解释：
你的 id 为 0（绿色），你的朋友包括（黄色）：
id 为 1 -> watchedVideos = ["C"] 
id 为 2 -> watchedVideos = ["B","C"] 
你朋友观看过视频的频率为：
B -> 1 
C -> 2

典型的BFS题，我们直接求出第lever层的朋友，将lever层的朋友添加到map（单词->单词次数）中，然后将map中元素添加到一个vector中，然后进行排序（频率升序排序；若频率相同，则按字典序由小到大），最后结果添加字符串结果。
代码如下：


class Solution {
public:
    //题解：bfs+sort
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n=friends.size();
        vector<bool> visited(n,false);
        queue<int> q;
        visited[id]=true;
        q.push(id);
        
        //步骤一：找出所有 Level k 的好友
        for(int i=1;i<=level;++i){
            int size=q.size();
            for(int j=0;j<size;++j){
                int top=q.front();q.pop();
                for(auto it:friends[top]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it]=true;
                    }
                }
            }
        }

        //步骤二：统计好友观看过的视频
        map<string,int> record;
        while(!q.empty())
        {
            int top=q.front();q.pop();
            for(const auto& it:watchedVideos[top]){
                record[it]++;
            }
        }

        //步骤三：将视频按照要求排序
        vector<pair<string,int>> vid(record.begin(),record.end());
        sort(vid.begin(),vid.end(),[](const pair<string,int>& a,const pair<string,int>& b){
            return a.second<b.second||(a.second==b.second&&a.first<b.first);
        });
        vector<string> res;
        for(auto &it:vid){
            res.push_back(it.first);
        }
        return res;
    }
};
