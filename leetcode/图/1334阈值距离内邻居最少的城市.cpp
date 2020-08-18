有 n 个城市，按从 0 到 n-1 编号。给你一个边数组 edges，其中 edges[i] = [fromi, toi, weighti] 代表 fromi 和 toi 两个城市之间的双向加权边，距离阈值是一个整数 distanceThreshold。

返回能通过某些路径到达其他城市数目最少、且路径距离 最大 为 distanceThreshold 的城市。如果有多个这样的城市，则返回编号最大的城市。

注意，连接城市 i 和 j 的路径的距离等于沿该路径的所有边的权重之和。

示例 1：

输入：n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
输出：3
解释：城市分布图如上。
每个城市阈值距离 distanceThreshold = 4 内的邻居城市分别是：
城市 0 -> [城市 1, 城市 2] 
城市 1 -> [城市 0, 城市 2, 城市 3] 
城市 2 -> [城市 0, 城市 1, 城市 3] 
城市 3 -> [城市 1, 城市 2] 
城市 0 和 3 在阈值距离 4 以内都有 2 个邻居城市，但是我们必须返回城市 3，因为它的编号最大。

//图的最短路问题
//floyd算法


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dp[n][n];
        memset(dp,0x3f,sizeof(dp));
        for(const auto& edge:edges){
            dp[edge[0]][edge[1]] = dp[edge[1]][edge[0]] = edge[2];
        }
        for(int k =0;k<n;k++){
            for(int i =0;i<n;i++){
                for(int j =0;j<n;j++){
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        int res = 0,minNum = INT_MAX;
        for(int i =0;i<n;++i){
            int cnt = 0;
            for(int j =0;j<n;j++){
                if(i!=j&&dp[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=minNum){
                minNum= cnt;
                res =i;
            }
        }
        return res;
    }
};

//dijkstra算法
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dist[n];
        memset(dist,0x3f,sizeof(dist));
        map<int,set<pair<int,int>>> adjacent;
        for(const auto& edge:edges){
            int a = edge[0],b = edge[1],w = edge[2];
            adjacent[a].insert(make_pair(b,w));
            adjacent[b].insert(make_pair(a,w));
        }
        pair<int,int>res(0x3f3f3f3f,0);
        for(int s = 0;s<n;s++){
            memset(dist,0x3f,sizeof(dist));
            dist[s] = 0;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
            q.push(make_pair(0,s));
            while(!q.empty()){
                pair<int,int>p = q.top();q.pop();
                int v = p.second;
                if(dist[v]<p.first)continue;
                for(const auto& edge :adjacent[v]){
                    if(dist[edge.first]>dist[v]+edge.second){
                        dist[edge.first] = dist[v]+edge.second;
                        q.push(make_pair(dist[edge.first],edge.first));
                    }
                }
            }
            int cnt = 0;
            for(int i =0;i<n;++i)if(dist[i]<=distanceThreshold)cnt++;
            if(cnt<=res.first){
                res.first = cnt;
                res.second = s;
            }
        }
        return res.second;
    }
};