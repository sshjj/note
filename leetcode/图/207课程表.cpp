你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]

给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？

示例 1:

输入: 2, [[1,0]] 
输出: true
解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。

//这一题求得就是判断图中是否有环！！！！
//拓扑排序，
//也就是先找到入度为 0 的节点（因为不存在环路，一定存在入度为 0 的节点），
//然后把该节点移除，相邻节点的入度 -1，以此类推，直到不存在入度为 0 的节点，
//这是拓扑排序的思路


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int m = prerequisites.size();
        vector<int>vec1(numCourses,0);
        vector<vector<int>>vec2(numCourses);
        for(vector<int>pre:prerequisites){
            vec1[pre[1]]++;
            vec2[pre[0]].push_back(pre[1]);
        }
        queue<int>q;
        for(int i = 0;i<numCourses;i++){
            if(vec1[i] == 0)q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            for(int i=q.size();i>0;i--){
                int cur = q.front();q.pop();
                cnt ++;
                for(int course:vec2[cur]){
                    if(--vec1[course] == 0)
                        q.push(course);
                }
            }
        }
        return cnt == numCourses;
    }
};


/////////////////////////////////
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       int m = prerequisites.size();
       vector<int>flags(numCourses,0);
       vector<vector<int>>vec2(numCourses);
       for(vector<int>pre:prerequisites){
           vec2[pre[0]].push_back(pre[1]);
       } 
       for(int i = 0;i<numCourses;i++){
           if(!dfs(vec2,flags,i))return false;
       }
        return true;
    }
    bool dfs(vector<vector<int>>&vec2,vector<int>&flags,int i){
        if(flags[i] == 1)return false;
        if(flags[i] == -1)return true;
        flags[i] = 1;
        for(int course:vec2[i])
            if(!dfs(vec2,flags,course))return false;
        flags[i] = -1;
        return true;
    }
};