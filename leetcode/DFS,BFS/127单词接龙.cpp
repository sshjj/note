给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s;
        for(auto& x:wordList)s.insert(x);
        queue<pair<string,int>>q;
        q.push(make_pair(beginWord,1));
        string tmp;
        int step;
        while(!q.empty()){
            if(q.front().first == endWord)
                return q.front().second;
            tmp = q.front().first;
            step = q.front().second;
            q.pop();

            char ch;
            for(int i = 0;i<tmp.size();i++){
                ch = tmp[i];
                for(char c = 'a';c<='z';c++){
                    if(ch == c)continue;
                    tmp[i] = c;
                    if(s.find(tmp)!=s.end()){
                        q.push({tmp,step+1});
                        s.erase(tmp);
                    }
                    tmp[i] = ch;
                }
            }
        }
        return 0;
    }
};