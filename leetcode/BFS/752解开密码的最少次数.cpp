你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。
输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
输出：6
解释：
可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
因为当拨动到 "0102" 时这个锁就会被锁定。
// BFS 方法
class Solution {
public:
    string plusone(string s,int j){
        if(s[j] == '9')
            s[j] = '0';
        else
            s[j]+=1;
        return s;
    }
    string minusone(string s,int j){
        if(s[j] == '0')
            s[j] = '9';
        else 
            s[j] -=1;
        return s;
    }
    int openLock(vector<string>& deadends, string target) {
        set<string> deads ;
        for(auto s:deadends)deads.insert(s);
        set<string>v;
        queue<string> q;
        int step =0;
        q.push("0000");
        v.insert("0000");
        while(!q.empty()){
            int n = q.size();
            for(int i =0;i<n;i++){
                string cur = q.front();
                q.pop();
                if(deads.count(cur))
                    continue;
                if(cur == target)
                    return step;

                for(int j  =0;j<4;j++){
                    string up = plusone(cur,j);
                    if(!v.count(up)){
                        q.push(up);
                        v.insert(up);
                    }
                    string down = minusone(cur,j);
                    if(!v.count(down)){
                        q.push(down);
                        v.insert(down);
                    }
                }
            }
            step++;
        }
        return -1;
    }

};

双向 BFS 优化
篇幅所限，这里就提一下区别：
传统的 BFS 框架就是从起点开始向四周扩散，遇到终点时停止；
而双向 BFS 则是从起点和终点同时开始扩散，当两边有交集的时候停止
图示中的树形结构，如果终点在最底部，按照传统 BFS 算法的策略，会把整棵树的节点都搜索一遍，最后找到 target；
而双向 BFS 其实只遍历了半棵树就出现了交集，也就是找到了最短距离。
从这个例子可以直观地感受到，双向 BFS 是要比传统 BFS 高效的。
双向 BFS 也有局限，因为你必须知道终点在哪里

class Solution {
public:
    string plusone(string s,int j){
        if(s[j] == '9')
            s[j] = '0';
        else
            s[j]+=1;
        return s;
    }
    string minusone(string s,int j){
        if(s[j] == '0')
            s[j] = '9';
        else 
            s[j] -=1;
        return s;
    }
    int openLock(vector<string>& deadends, string target) {
        set<string> deads ;
        for(auto s:deadends)deads.insert(s);
        set<string>q1;
        set<string>q2;        
        set<string>v;
        int step =0;
        q1.insert("0000");
        q2.insert(target);

        while(!q1.empty() && !q2.empty()){
            set<string>temp;
            for(string cur:q1){
                if(deads.count(cur))
                    continue;
                if(q2.count(cur))
                    return step;
                v.insert(cur);
                for(int j = 0;j<4;j++){
                    string up = plusone(cur,j);
                    if(!v.count(up))
                        temp.insert(up);
                    string down = minusone(cur,j);
                    if(!v.count(down))
                        temp.insert(down);
                }
            }
        step++;
        q1 = q2;
        q2 = temp;
        }
        return -1;
    }
};